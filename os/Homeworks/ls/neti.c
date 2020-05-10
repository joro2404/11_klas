#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <math.h>
#include <string.h>

int first = 1;

int show_hidden = 0;
int show_without_prev_next = 0;
int detailed_info = 0;
int recursive = 0;

int errors = 0;

void print_files(const char* input);
void print_dirs(const char* input, int many_args);
char determine_mode(const char *input);
void determine_and_print_info(const char *input);

int find_total_blocksize(const char* input);

int check_if_hidden(const char *name); //show a hidden file if show_hidden == 1
int check_for_args(const char *arg);
int applies_to_A(const char *input);

void print_error(int err, const char* name);

int main(int argc, char const *argv[])
{
	int many_args;
	char *file_args[argc];
	char *dir_args[argc];
	int files = 0;
	int dirs = 0;
	int options = 0;

	for (int i = 1; i < argc; ++i) //sort out files and dirs and check for options
	{
		if(options += check_for_args(argv[i]) == 1)
		{
			continue;
		}
		if (determine_mode(argv[i]) == '!')
		{
			continue;
		}
		
		if (determine_mode(argv[i]) == 'd')
		{
			dir_args[dirs] = argv[i];
			dirs++;
		}
		else if (determine_mode(argv[i]) != 'd')
		{
			file_args[files] = argv[i];
			files++;
		}
	}

	many_args = (options && (argc-options-errors <= 2))
				|| ((options == 0) && (argc-errors <= 2)) ? 0 : 1; //fucking fix the black magic here

	if (recursive)
	{
		many_args = 1;
	}

	for (int i = 0; i < files; ++i)
	{
		if (i != 0)
		{
			first = 0;
		}
		print_files(file_args[i]);
	}

	for (int i = 0; i < dirs; ++i)
	{
		if (i != 0)
		{
			first = 0;
		}
		print_dirs(dir_args[i], many_args);
	}

	if (files + dirs == 0 && !errors)
	{
		print_dirs(".", many_args);
	}
}

void print_files(const char* input)
{
	if (!check_if_hidden(input) || show_hidden 
	|| (show_without_prev_next && !applies_to_A(input))) //show when hidden && -a || not hidden || when -A
	{
		printf("-");
		if (detailed_info)
		{
			determine_and_print_info(input);
		}
		printf(" %s\n", input);
	}
}

void print_dirs(const char* input, int many_args)
{
	int total_block_size = 0;

	if (!first)
	{
		printf("\n");
	}
	if (many_args)
	{
		printf("%s:\n", input);
	}
	
	if (determine_mode(input) == 'd')
	{
		struct dirent *directory_content;
		DIR *dir = opendir(input);
		if (dir == NULL)
		{
			print_error(2, input);
			return;
		}else{
			while(directory_content = readdir(dir)) //find total blocks size
			{
				char content_name[300];
				sprintf(content_name, "%s/%s", input, directory_content->d_name);

				if (!check_if_hidden(directory_content->d_name) || show_hidden 
					|| (show_without_prev_next && !applies_to_A(directory_content->d_name)))
				{
					if (detailed_info)
					{
						total_block_size += find_total_blocksize(content_name);
					}
				}
			}

			closedir(dir);
		}

		if (detailed_info)
		{
			printf("total %d\n", total_block_size/2);
		}

		dir = opendir(input);
		if (dir == NULL)
		{
			print_error(2, input);
		}else{
			while(directory_content = readdir(dir)) //print dirs
			{
				char content_name[300];
				sprintf(content_name, "%s/%s", input, directory_content->d_name);
				
				if (!check_if_hidden(directory_content->d_name) || show_hidden 
					|| (show_without_prev_next && !applies_to_A(directory_content->d_name)))
				{
					printf("%c", determine_mode(content_name));
					if (detailed_info)
					{
						determine_and_print_info(content_name);
					}
					printf(" %s\n", directory_content->d_name);
				}
			}

			closedir(dir);
		}


		if (recursive)
		{
			dir = opendir(input);
			if (dir == NULL)
			{
				print_error(2, input);
			}else{
				while(directory_content = readdir(dir)) 
				{
					char content_name[300];
					sprintf(content_name, "%s/%s", input, directory_content->d_name);
					
					if (!check_if_hidden(directory_content->d_name) || show_hidden 
					|| (show_without_prev_next && !applies_to_A(directory_content->d_name)))
					{
						if (determine_mode(content_name) == 'd' 
							&& strcmp(".", directory_content->d_name) != 0 
							&& strcmp("..", directory_content->d_name) != 0)
						{
							printf("\n");
							print_dirs(content_name, many_args);
						}
					}
				}

				closedir(dir);
			}
		}
	}
}

int find_total_blocksize(const char* input)
{
	struct stat st;
	stat(input, &st);

	return st.st_blocks;
}

char determine_mode(const char *input)
{
	struct stat st;
	if(stat(input, &st) != -1)
	{
		if(S_ISREG(st.st_mode))
		{
			return '-';
		}
		if(S_ISDIR(st.st_mode))
		{
			return 'd';
		}
		if(S_ISCHR(st.st_mode))
		{
			return 'c';
		}
		if(S_ISBLK(st.st_mode))
		{
			return 'b';
		}
		if(S_ISFIFO(st.st_mode))
		{
			return 'p';
		}
		if(S_ISLNK(st.st_mode))
		{
			return 'l';
		}
		if(S_ISSOCK(st.st_mode))
		{
			return 's';
		}
	}else{
		print_error(1, input);
		return '!';
	}
}

void determine_and_print_info(const char *input)
{
	struct stat st;
	stat(input, &st);

	struct passwd *pwd;
	struct group *grp;

	char date[20];
    
    printf("%s", (st.st_mode & S_IRUSR) ? "r" : "-");// condition ? if_true : if_fasle 
    printf("%s", (st.st_mode & S_IWUSR) ? "w" : "-");
    printf("%s", (st.st_mode & S_IXUSR) ? "x" : "-");
    printf("%s", (st.st_mode & S_IRGRP) ? "r" : "-");
    printf("%s", (st.st_mode & S_IWGRP) ? "w" : "-");
    printf("%s", (st.st_mode & S_IXGRP) ? "x" : "-");
    printf("%s", (st.st_mode & S_IROTH) ? "r" : "-");
    printf("%s", (st.st_mode & S_IWOTH) ? "w" : "-");
    printf("%s ", (st.st_mode & S_IXOTH) ? "x" : "-");
    printf("%ld ",st.st_nlink);
    pwd = getpwuid(st.st_uid);
    printf("%s ", pwd->pw_name);
    grp = getgrgid(st.st_gid);
    printf("%s ", grp->gr_name);
	printf("%ld ", st.st_size);
	strftime(date, 20, "%b %d %H:%M", localtime(&(st.st_mtim)));
	printf("%s", date);
}

int check_if_hidden(const char *name)
{
	if (name[0] == '.')
	{
		return 1;
	}

	return 0;
}

int check_for_args(const char *arg)
{
	if (arg[0] == '-')
	{
		if (strchr(arg, 'a') != NULL)
		{
			show_hidden = 1;
		}
		if (strchr(arg, 'A') != NULL)
		{
			show_without_prev_next = 1;
		}
		if (strchr(arg, 'l') != NULL)
		{
			detailed_info = 1;
		}
		if (strchr(arg, 'R') != NULL)
		{
			recursive = 1;
		}

		return 1;
	}

	return 0;
}

int applies_to_A(const char *input)
{
	if (strcmp(".", input) == 0 || strcmp("..", input) == 0)
	{
		return 1;
	}
	return 0;
}

void print_error(int err, const char* name)
{
	errors++;
	char error[100 + strlen(name)];
	switch(err)
	{
	case 1:
		sprintf(error, "ls: cannot access '%s'", name);
		perror(error);
		break;
	case 2:
		sprintf(error, "ls: cannot open directory '%s'", name);
		perror(error);
		break;
	}
}