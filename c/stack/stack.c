#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} node;

typedef struct _stack{
    node* top;
    node* end;
} stack;

void stackPrint( stack* s){
    node* n;
    if(NULL != s && NULL != s->top)
        n= s->top;
    while( NULL != n){
        printf("%d ",n->data);
        n = n->next;
    }
}

stack *stackNew(){
    stack* s = (stack*)malloc(sizeof(stack));
    s->end = s->top = NULL;
    return s;
}

stack *push( stack* s, int d){
    if ( NULL == s)
    {
        s = stackNew();
    }
    node* n = (node*)malloc(sizeof(node));
    n->data = d;
    n->next = s->top;
    s->top = n;
    if ( NULL == s->end)
    {
        s->end = n;
    }
    return s;
}

node *pop( stack*s ){
    if ( NULL == s || NULL == s->top)
        return NULL;
    node *n = s->top;
    s->top = s->top->next;
    return n;
}

void stackFree( stack* s) {
    while( NULL != s && NULL !=s->top ){
        free( pop(s) );
    }
}

int main(){
    stack *s = NULL;
    node *n;
    int d;
    do{
        printf("push?\n");
        scanf("%d",&d);
        if ( 0 != d ) {
            s = push( s, d);
        }
    }while( 0 != d );
    stackPrint(s);
    printf("pop\n");
    while( NULL !=( n = pop(s) ) ){
        printf("%d ",n->data);
        free(n);
    }

    stackFree( s );
    free (s );
    
    return 0;
}

