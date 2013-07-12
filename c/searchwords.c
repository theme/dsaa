#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    char *flab[] = {
        "actually",
        "just",
        "quite",
        "really",
        NULL
    };

    printf("lookup just: %d\n",lookup("just",flab));
    printf("strstr: %s\n", strstr("thisisastring", "is"));
    printf("strstr: %s\n", strchr("thisisastring", 'a'));
    ps("ps() in main");
    isNumOrLetter('a');
    //printf("is num or letter: a? %d", isNumOrLetter('a'));
    return 0;
}

int lookup(char *word, char *array[]){
    int i;
    ps("ps() in lookup()");
    for( i=0; array[i] != NULL; i++ )
        if (strcmp(word,array[i]) == 0 )
            return i;
    return -1;
}

bool isNumOrLetter(char *c){
    char a = *c;
    if (( 0 <= a) && ( a <= 9))
        return true;
    else if ( ('a' <= a) && ( a <= 'z') )
        return true;
    else if ( ('A' <= a) && ( a <= 'Z') )
        return true;
    else
        return false;
}

int ps(char * s){
    printf("%s\n",s);
}
