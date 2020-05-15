//------------------------------------------------------------------------
// NAME: Georgi Lyubenov
// CLASS: XIb
// NUMBER: 10
// PROBLEM: #2
// FILE NAME: strcat.c
// FILE PURPOSE:
// имплементация на функцията strcat от библиотеката <string.h>
// ...
//------------------------------------------------------------------------

#include<stdio.h>

char *strcat(char* destination, const char* source ){

    //------------------------------------------------------------------------
    // FUNCTION: strcat
    // предназначение на функцията -> обединява два стринга в един, връща обединения стринг
    // PARAMETERS: destination и source два стринга
    //
    // тяхното значение -> от destination и source се обединяват в destination
    //------------------------------------------------------------------------

    int count,i; //дължините на двата стринга. count за destination и i за source

    for(count=0; destination[count] != '\0'; count++); //намираме дължината на source
    for(i = 0; source[i] != '\0'; i++){

        destination[count+i] = source[i]; //добавяме source в destination
    }

    destination[count+i] = '\0'; //добавяме терминираща 0 накрая на получения слят масив

    return destination; //връщаме получения слят масив от функцията
}
