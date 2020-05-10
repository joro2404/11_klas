// NAME: Peter-Gabriel Matev
// CLASS: XIb
// NUMBER: 22
// PROBLEM: #5
// FILE NAME: strdubpg.c
// FILE PURPOSE: 
// създава пойнтер, сочещ към динамично заделена памет, в която се намира копие на подаден низ

#include <stdlib.h>
#include <stdio.h>

char *strdup(const char *s){
    int counter = 0;
    
    while(s[counter])counter++;
    
    char *ns = malloc(counter*sizeof(char));
    
    for(int i = 0; i<counter; i++){
        ns[i] = s[i];
    }

    return ns;
}
