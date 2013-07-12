#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
        printf("need 2 string as arguments");

    char* p = strstr( argv[2], argv[1] );

    if ( p != NULL )
    {
        printf("the %ldth char", p - argv[2] +1);
    }
    else
    {
        printf("not a sub string");
    }
    printf("\n");
}
