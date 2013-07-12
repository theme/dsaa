#include <stdio.h>

#ifndef ulong
#define ulong unsigned long 
#endif

int main(int argc, char *argv[])
{
    char  *array[] = {
        "this","veryverylonglongaaaaaaaaaaaaaaaaaaaaarray","is a word."
    };

    char *lastptr = array[0];

    int i = 0;
    for(;i < 3; i++){
        printf("string %d = %s\n", i, array[i]);
        printf("array[%d] = 0x%08lx\n", i, (ulong)array[i]);
        printf("lastptr = %08lx, offset to last ptr = %ld\n", (ulong)lastptr, (ulong)(array[i]) - (ulong)(lastptr));
        lastptr = array[i];
        printf("sizeof(array[%d})= %ld\n", i, sizeof(array[i]));
    }
}
