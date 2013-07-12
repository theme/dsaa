#include <stdio.h>

int main()
{
    char c = -1;
    signed char sc = -1;
    unsigned char uc = -1;

    printf("\fc=%d,sc=%d,uc=%d\n",c,sc,uc);

    printf("sizeof(signed int) = %ld\n",sizeof(signed int));
    printf("sizeof(unsigned int) = %ld\n",sizeof(unsigned int));
    printf("sizeof(signed char) = %ld\n",sizeof(signed char));
    printf("sizeof(unsigned char) = %ld\n",sizeof(unsigned char));

    unsigned int ui = 0xaabbccdd;
    uc = ui;

    printf("ui = %X, uc = %X\n", ui,uc);
    
}
