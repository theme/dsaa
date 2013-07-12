#include <stdio.h>

int main(){
    int arr[] = {1,2,3,4,5};

    int *ptr = arr;
    printf( "%d,%d\n", *(++ptr),*ptr);
    printf( "%d,%d\n", *ptr,*(++ptr));
}
