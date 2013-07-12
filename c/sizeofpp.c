#include <stdio.h>

int sf(int var[])
{
    printf( "in sf:%ld\n",sizeof(var));
}

int main()
{
    int var[100];
    int **a[3][4];
    int b[3][4];

    printf("sizeof(size_t)=%ld\n",sizeof(size_t));
    printf( "%ld\n",sizeof(var));
    printf( "sizeof(int*)%ld\n",sizeof(int*));
    printf( "sizeof(int)%ld\n",sizeof(int));
    printf( "sizeof(float*)%ld\n",sizeof(float*));
    printf( "sizeof(float)%ld\n",sizeof(float));
    printf( "sizeof(**a[3][4])%ld\n",sizeof(a));
    printf( "sizeof(*b[3][4])%ld\n",sizeof(b));
    printf( "sizeof(b[3][4])%ld\n",sizeof(b));
    sf(var);
}
