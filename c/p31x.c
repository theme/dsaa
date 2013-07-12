#include <stdio.h>

int main(){
    int x = 0xffffffff;

    int i;
    for(i=0; i < 33; i++){
        printf( "%d, %o\n",i,x);
        x = x & (x-1);
    }
}

