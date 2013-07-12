#include <stdio.h>

#define MAX 500000

int main()
{
    int i;
    for( i = 0; i< MAX; i++){
        if (isPrime(i))
        {
            //printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int isPrime(int n){
    int i;
    for( i = 2; i * i < n; i++)
    {
        if ( n % i == 0)
        {
            return 0;
        }
    }
    return 1 ;
}

