#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
}node;

typedef struct _queue{
    node* a;
    node* z;
}queue;

queue* enqueue(queue *q, int d){
    if ( NULL == q){
        q = (queue*) malloc( sizeof(queue));
        q->a = q->z = NULL;
    }

    node* n = (node*)malloc( sizeof(node));
    n->data = d;
    n->next = NULL;

    if ( NULL != q->z)//not empty
    {
        q->z->next = n;
        q->z = n;
    }else{
        q->z = q->a = n;
    }
    return q;
}

node* dequeue(queue* q) {
    node* n;
    if (NULL == q)
        return NULL;

    if ( NULL != q->a) {
        n = q->a;
        q->a = n->next;
    }
    return n;
}

int main(){
    queue *q = (queue *) malloc ( sizeof(queue) );
    q->a = q->z = NULL;
    int d;
    node *n;
    while(1){
        printf("enqueue?");
        scanf("%d",&d);
        if ( 0 != d)
            enqueue( q, d);
        else
            break;
    }
    printf("dequeue\n");
    while( NULL != (n = dequeue( q)) ){
        printf("%d ",n->data);
        free(n);
    }
    free( q);
}

