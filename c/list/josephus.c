#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} node;

void printl(node* n){
    if (NULL == n)
        return;
    node* p = n;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while( p != n && NULL != p);
    printf("\n");
}

node* create( int n ){
    int i;
    node *p, *nn,  *head;

    head = (node*) malloc( sizeof( node ));
    head->data = 1;
    p = head;

    for( i = 1 ; i < n; ++i) {
//        printl(head);
        nn = (node*) malloc( sizeof( node ));
        nn->data = i+1;
        p->next = nn;
        p = nn;
    }
    nn->next = head;

    return head;
}

void freeAll( node* n){
    if (NULL == n) 
        return;
    node *tmp, *p = n->next;
    while( p!= n){
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(n);
}

void josephus(int n, int k, int m){
    node* list, *p, *l;
    printf("create\n");
    list = create(n);
    printl( list );
    p = list;
    l = p;
    while( l->next != p ) l = l->next;

    printf("josephus\n");
    printf("k=%d\n",k);
    while( --k ){
        printf("move for k=%d\n",k);
        l= p , p= p->next;
    }
    printf("p->data=%d\n",p->data);
    printf("m=%d\n",m);
    while( n-- ){
        printl(p);
        int s = m;
        while( --s ) l= p , p= p->next;
        l->next = p->next;
        printf( "out %d\n", p->data);
        free(p);
        if ( l != p)
            p= l->next;
    }
    printf("done\n");
}

int main(){
    josephus(9,1,5);
    josephus(13,4,1);
    return 0;
}

