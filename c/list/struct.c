#include <stdio.h>

struct point
{
    int x;
    int y;
};


int main()
{
    struct point a = {1,2};
    printf("a.x=%d,a.y=%d\n",a.x,a.y);
}


