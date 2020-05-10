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


// a function to find the type of the file 
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
        char error[100 + strlen(filename)];
		sprintf(error, "ls: cannot access '%s'", filename);
		perror(error);
		return '!';
	}
}

void read_dir(char* dir_name){
    if(check)printf("\n");

    int is_recursive = 0;

    struct dirent *entry;
    DIR *dir = opendir(dir_name);

    if(dir == NULL){
        char error[100 + strlen(dir_name)];
		sprintf(error, "ls: cannot access '%s'", dir_name);
		perror(error);
    }else{
        if(arguments > 1)printf("%s:\n", dir_name);
        while(entry = readdir(dir)){
            char content_name[512];
            sprintf(content_name, "%s/%s", dir_name, entry->d_name);
            int is_printed = 0;

            if( (strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && entry->d_name[0] != '.' && normal_mode_flag == 1 && is_printed == 0){
                
                printf("%c", get_type_of_file(content_name));   
                printf(" %s\n", entry->d_name);
                is_printed++;
            }

            if( (strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && A_flag == 1 && is_printed == 0){
                printf("%c", get_type_of_file(content_name));   
                printf(" %s\n", entry->d_name);
                is_printed++;
            }

            if( (strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && R_flag == 1 && is_printed == 0){
                is_recursive = 1;
            }

            if((strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) && l_flag == 1 && is_printed == 0){
                printf("%c", get_type_of_file(content_name));
                // print_detailed_info(content_name);   
                printf(" %s\n", entry->d_name);
                is_printed++;
            }
            
        }

        closedir(dir);
    }
    
}

// void print_detailed_info(char* filename);

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

    if(A_flag == 0 && R_flag == 0 && l_flag == 0)normal_mode_flag = 1;

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
    }

    for(int i = arguments; i > 0; i--){
        if(i != arguments)check = 1;
        

        read_dir(dirs[i-1]);        
    }



    // printf("R_flag -> %d\nA_flag -> %d\nl_flag -> %d\n", R_flag, A_flag, l_flag);

    // for(int i = 0; i < arguments; i++){
    //     printf("%s\n", dirs[i]);
    // }
    return 0;
}