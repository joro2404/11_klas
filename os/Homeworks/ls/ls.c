//--------------------------------------------
// NAME: Georgi Lyubenov   
// CLASS: XIb
// NUMBER: 10
// PROBLEM: #4
// FILE NAME: ls.c (unix file name)
// FILE PURPOSE:
// implementation of the system function ls
//---------------------------------------------
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
#include <getopt.h>

int A_flag = 0;
int l_flag = 0;
int R_flag = 0;
int normal_mode_flag = 0;

int arguments = 0;
int count_of_files = 0;
int check = 0;



//getting the maggic to be done by https://stackoverflow.com/questions/10323060/printing-file-permissions-like-ls-l-using-stat2-in-c
//--------------------------------------------
// FUNCTION: print_detailed_info (име на функцията)
// предназначение на функцията get get the read, write and execute, and others as time and user, group
// PARAMETERS: filename, to get the current filepath
// списък с параметрите на функцията
// и тяхното значение
//----------------------------------------------
void print_detailed_info(char* filename){

    struct stat st;
	stat(filename, &st);

	struct passwd *pwd;
	struct group *grp;

	char date[20];

    // printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
    printf( (st.st_mode & S_IRUSR) ? "r" : "-");
    printf( (st.st_mode & S_IWUSR) ? "w" : "-");
    printf( (st.st_mode & S_IXUSR) ? "x" : "-");
    printf( (st.st_mode & S_IRGRP) ? "r" : "-");
    printf( (st.st_mode & S_IWGRP) ? "w" : "-");
    printf( (st.st_mode & S_IXGRP) ? "x" : "-");
    printf( (st.st_mode & S_IROTH) ? "r" : "-");
    printf( (st.st_mode & S_IWOTH) ? "w" : "-");
    printf( (st.st_mode & S_IXOTH) ? "x" : "-");
    printf(" %ld ",st.st_nlink);
    pwd = getpwuid(st.st_uid);
    printf("%s ", pwd->pw_name);
    grp = getgrgid(st.st_gid);
    printf("%s ", grp->gr_name);
	printf("%ld ", st.st_size);
    // printf("%ld ", st.st_size);
	strftime(date, 20, "%b %d %H:%M", localtime(&(st.st_mtime)));
	printf("%s", date);
}

// a function to find the type of the file 
//--------------------------------------------
// FUNCTION: get_type_of_file (име на функцията)
// предназначение на функцията get the type as said in the presentation
// PARAMETERS: filename, same as the previous
// списък с параметрите на функцията
// и тяхното значение
//----------------------------------------------
char get_type_of_file(char *filename){

	struct stat st;
	if(stat(filename, &st) != -1){

		if(S_ISREG(st.st_mode))return '-';
		
		if(S_ISDIR(st.st_mode))return 'd';
		
        if(S_ISCHR(st.st_mode))return 'c';
		
		if(S_ISBLK(st.st_mode))return 'b';
		
		if(S_ISFIFO(st.st_mode))return 'p';
		
		if(S_ISLNK(st.st_mode))return 'l';
		
		if(S_ISSOCK(st.st_mode))return 's';
		
	}else{
        perror("stat");
	}
}
//--------------------------------------------
// FUNCTION: read_dir (име на функцията)
// предназначение на функцията whole logic and the body of the program
// PARAMETERS: dir_name, to get the directory
// списък с параметрите на функцията
// и тяхното значение
//----------------------------------------------

void read_dir(char* dir_name){
    if(check)printf("\n");
    if(arguments > 1 || R_flag == 1)printf("%s:\n", dir_name);

    int is_recursive = 0;
    int total_block_size = 0;

    if(get_type_of_file(dir_name) == 'd'){

        struct dirent *entry;
        DIR *dir = opendir(dir_name);
        if(dir == NULL){
            perror("opendir");
        }else{
            // if(arguments > 1)printf("%s:\n", dir_name);
            while(entry = readdir(dir)){
                char file_name[512];
                sprintf(file_name, "%s/%s", dir_name, entry->d_name);
                int is_added = 0;

                if((strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && A_flag == 1 && is_added == 0){
                    if(l_flag == 1){
                        struct stat st;
                        stat(file_name, &st);

                        total_block_size += st.st_blocks;
                        is_added++;
                    }
                }

                if((strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && entry->d_name[0] != '.' && l_flag == 1 && is_added == 0){
                    struct stat st;
                    stat(file_name, &st);

                    total_block_size += st.st_blocks;
                    is_added++;
                }

            }

            closedir(dir);
        }

        dir = opendir(dir_name);
        if(dir == NULL){
            perror("opendir");
        }else{
            
            if (l_flag == 1)printf("total %d\n", total_block_size/2);
            while(entry = readdir(dir)){
                char file_name[512];
                sprintf(file_name, "%s/%s", dir_name, entry->d_name);
                int is_printed = 0;

                if((strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && A_flag == 1 && is_printed == 0){
                    // if (l_flag == 1)printf("total %d\n", total_block_size/2);
                    printf("%c", get_type_of_file(file_name));
                    if(l_flag == 1)print_detailed_info(file_name);
                    printf(" %s\n", entry->d_name);
                    is_printed++;
                }

                if((strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && entry->d_name[0] != '.' && is_printed == 0){
                    // if (l_flag == 1)printf("total %d\n", total_block_size/2);
                    printf("%c", get_type_of_file(file_name));
                    if(l_flag == 1)print_detailed_info(file_name);
                    printf(" %s\n", entry->d_name);
                    is_printed++;
                }

                if(R_flag == 1)is_recursive = 1;
                
            }

            closedir(dir);
        }
        if(is_recursive == 1){
        
            dir = opendir(dir_name);
            if(dir == NULL){
                perror("opendir");
            }else{
                // if(arguments > 1)printf("%s:\n", dir_name);
                while(entry = readdir(dir)){
                    char file_name[512];
                    sprintf(file_name, "%s/%s", dir_name, entry->d_name);
                    int is_added = 0;

                    if( get_type_of_file(file_name) == 'd' && (strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0)){
                        printf("\n");
                        // printf("%s:\n", file_name);
                        read_dir(file_name);
                    }

                }

                closedir(dir);
            }
        }
    }
}



int main(int argc, char** argv){

    char* dirs[argc];
    char* files[argc];
    int opt;
    //getting the input by the user getopt() STRONG!
    while ((opt = getopt(argc, argv, "AlR")) != -1){
        switch (opt){
            case 'A':
                A_flag = 1;
                break;

            case 'l':
                l_flag = 1;
                break;

            case 'R':
                R_flag = 1;
                break;

            case '?':
                break;

            default:
                break;
        }
    }

    if(A_flag == 0 && l_flag == 0 && R_flag == 0)normal_mode_flag = 1;

    for(int i = 0; optind < argc; optind++, i++){      
        if(get_type_of_file(argv[optind]) == 'd'){
            dirs[arguments] = argv[optind];
            arguments++;
        }
        else{
            files[count_of_files] = argv[optind];
            count_of_files++;
        }
        
    }


    if(arguments == 0 && count_of_files == 0){
        dirs[0] = ".";
        arguments++;
    }

    for(int i = count_of_files; i > 0; i--){
        printf("- %s\n", files[i-1]);
        check = 1;
    }

    for(int i = arguments; i > 0; i--){
        if(i != arguments)check = 1;
        

        read_dir(dirs[i-1]);        
    }



    return 0;
}