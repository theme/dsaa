#include <stdio.h>
int f(int x, int y)
{
    return (x&y) + ((x^y)>>1);
}

int main()
{
    int i, x = -2, y = -5;
    for( i=0; i< 10; i++){
        printf(" x=%d, y=%d", x,y);
        printf(" (x+y)/2 = %d\t", (x+y)/2);
        printf(" f(x,y) = %d\n", f(x,y));
        x+=1;
        y+=1;
    }

}
