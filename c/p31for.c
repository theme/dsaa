#include <stdio.h>
int main(){
    int a = 1,b=2,x,y;

    if ( b ++ && a < 1 )
    {
        printf( "a < 1" );
    }
        printf( "%d, %d", a,b );

    if (a <= 1 && b++)
    {
        printf( "a<= 1");
    }
        printf( "%d, %d", a,b );
}
