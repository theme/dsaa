#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode {
    int data;
    struct _dnode *pre;
    struct _dnode *next;
} dnode;

dnode *create(){
    dnode *p, *n, *head = NULL;

    int d;
    printf("input new node data ?\n");
    scanf("%d",&d);
    if ( 0 != d)
    {
        head = (dnode * ) malloc( sizeof(dnode) );
        head->data = d;
        head->pre = NULL;
        head->next = NULL;
    }else {
        printf( " dlist not created \n");
        return head;
    }
    p = head;

    while( d != 0 ){
        printf("input new node data ?\n");
        scanf( "%d", &d );
        if ( d != 0 )
        {
            n = (dnode *) malloc (sizeof(dnode ));
            n->data = d;
            p->next = n;
            n->pre = p;
            n->next = NULL;

            p = n;
        }
    }
    return head;
}

void dprint( dnode* head){
    if (NULL == head)
        return;
    printf("%d ", head->data);
    if ( NULL != head->next)
        dprint( head->next );
}


void dfree( dnode *head ){
    if (NULL == head)
        return;
    if ( NULL != head->next)
    {
        dfree( head->next );
    }
    free( head );
}

dnode *ddel( dnode *head, const int d){
    if ( NULL == head)
        return NULL;
    dnode *n;
//search
    n = head;
    while( n->data != d && NULL != n->next ) {
        n = n->next;
    }

    if( n->data !=d && NULL == n->next )  // not found
    {
        printf(" data %d  not found, del no node.", d);
    }else { //found
        if ( head == n) {
            head = n->next;
            n->next->pre = NULL;
        }else// ( head != n) 
            n->pre->next = n->next;
        if ( NULL != n->next )
            n->next->pre = n->pre;
        free( n );
    }
    return head;
}

dnode *dinsert( dnode *head, const int d){
    if ( NULL == head)
        return NULL;
    dnode *p, *n = (dnode*) malloc( sizeof(dnode));
    n->data = d;

    p = head;
    while( p->data < d && NULL != p->next ){
        p = p->next;
    }

    if ( p->data >= d) {   //before head
        if ( head == p)
        {
            n->next = head;
            n->pre = NULL;
            head->pre = n;
            head = n;
        }else{ //after head, before end
            p->pre->next = n;
            n->pre = p->pre;
            p->pre = n;
            n->next = p;
        }
    }else // p_data <d && NULL == p->next //after end
    {
        p->next = n;
        n->pre = p;
        n->next = NULL;
    }

    return head;
}

int main(int argc, char* argv[]) {
    dnode* head = create();
    int d;

    dprint( head );
    printf("\n");

    printf("insert a node by data?\n");
    scanf("%d",&d);
    head = dinsert( head, d);
    dprint( head );
    printf("\n");

    
    printf("del a node by data?\n");
    scanf("%d",&d);
    head = ddel( head, d);
    dprint( head );
    printf("\n");

    dfree( head );
    return 0;
}
