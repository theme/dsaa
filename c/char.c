#include <stdio.h>

#define MAX 255

int main(){
    char p[MAX+1];
    unsigned char ch;
    for( ch=0; ch < MAX; ch++){
        p[ch]=ch;
        printf("p[%d]=%d\n",ch,(unsigned char)p[ch]);
    }
    p[ch] = ch;
    printf("last%d\n",p[ch]);
}
    
