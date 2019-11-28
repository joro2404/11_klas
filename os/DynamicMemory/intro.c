#include <stdio.h>

int main() {

    int arr[200];

    arr[0] = 5;
    arr[1] = 6;
    arr[2] = 7;

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);

    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);


    void *va = &arr[0];
    va--;
    int *ia = (int *) va;
    *ia = 5;

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    //printf("%d\n", *(int *) va);
}