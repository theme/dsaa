#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main()
{
    int a[N];
    int i;
    srand( time (NULL ) );
    for( i = 0; i< N; i++){
        a[i] = N -  rand() / (RAND_MAX / N/2 +1);
        printf("%d ", a[i]);
        //printf("%d ",rand() % N  );
    }
    printf("\n minSum = %d\n", minSum(a,N) );
    return 0;
}

int minSum(const int a[],const int n)
{
    int minSum, thisSum, j;
    int l1 = 0,l2 = 0,h = 0;
    thisSum = 0;
    minSum = 0;
    for( j = 0; j < n; j++){
        thisSum += a[j];

        if ( thisSum < minSum)
        {
            minSum = thisSum;
            h = j;
            if (  l2 <= h)
                l1 = l2;
        }else if ( thisSum > 0){
            thisSum = 0;
            l2 = j+1;
        }
    }
    printf( "minSum [%d,%d]\n",l1,h);
    return minSum;
}

