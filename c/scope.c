#include <stdio.h>

void f();

int main(int argc, char* argv[])
{
    int a = 1;
    a++;
    {
        int argc = 1;
        printf("inner %d\n", argc);
    }

    int b = 2;
    b++;
    printf("outer %d\n", argc);
    int d = 4;

    {
        int argc = 1;
        printf("2nd inner %d\n", argc);
    }
    int c = 3;
    c += 3;
    int e = c;

    printf("%d, %d, %d\n", a,b,c);
    f();
}

void f()
{
    printf("f\n");
}

