#include <stdio.h>

int main(){
    int  i = 0, k = 7;
    while( --k){
        printf( "i= %d, k= %d\n",i,k);
        i++;
    }
    printf( "out of while\n i= %d, k= %d\n",i,k);
    return 0;
}
