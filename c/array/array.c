#include <stdio.h>
#include <string.h>
void test1() {
    printf(">>> test1\n\n");
    char c[][3] = { {'a','b','c'},{'e','f','g'}};
    char c2[2][3] = { "a","bcd"};
    int i,j ;

    printf("sizeof(c)= %ld \n", sizeof(c));
    for( i = 0; i < 2 ; ++i){
        for( j = 0 ; j< 3; ++j ){
            printf("c[%d][%d] = %c\t 0x%x\n",i,j,c[i][j],(int) c[i][j]);
        }
    }
    printf("sizeof(c2)= %ld \n", sizeof(c2));
    for( i = 0; i < 2 ; ++i){
        for( j = 0 ; j< 3; ++j ){
            printf("c2[%d][%d] = %c\t 0x%x\n",i,j,c2[i][j],(int) c2[i][j]);
        }
    }
}
void test2() {
    printf(">>> test2\n\n");
    char c3[] = {"aaabbbc"};
    char c4[6];
    char c5[] = {"123456"};
    strcpy(c4,c3);  //cross bounds access to c4
    printf("c3=%s, strlen(c3)=%lu\n",c3,strlen(c3));
    printf("c4 <= c3, c4(%p)=%s\n", c4,c4);
    printf("c4 <= c3, c5(%p)=%s\n", c5,c5);
    printf("c4[6]=0x%x\n", (int) c4[6]);
}

void test3(){
    printf(">>> test3\n\n");
    char tgt[10];
    char src[10];
    int i;
    printf("i (uninitialized) =%d\n",i);
    for( i=0; i<10; ++i) {
        src[i] = '0'+i;
        printf("%c ",'0'+i);
    }
    strcpy(tgt,src);//uncertain where will string src ends
    printf("\ntgt[10] <= src[10] : tgt = %s\n",tgt);//may cross tgt bounds
}

int main()
{
    int a[0];
    int a1[1] = {0xffffffff};

    printf("a[0]=%d\n",a[0]);
    printf("a1[1]=%d\n",a1[1]);
    printf("sizeof(a[0])=%ld\n",sizeof(a));
    printf("sizeof(a1[1])=%ld\n",sizeof(a1));
    test1();
    test2();
    test3();
}
