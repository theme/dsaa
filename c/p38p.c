#include <stdio.h>

int main()
{
    unsigned char a = 0xA5;
    unsigned char b = ~a>>4+1;
    printf(" b = %d\n", b);
    printf(" a=%x\n ~a=%x\n ~a>>5=%x\n",a,~a,~a>>5);
    return 0;
}
