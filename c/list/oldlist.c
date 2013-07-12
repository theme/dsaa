#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
}node;

int listLen( node* head ){
    int i = 0;
    while( NULL != head ){
        i++;
        head = head->next;
    }
    return i;
}

void listPrint( node* head ){
    while( NULL != head ){
        printf( "%d ", head->data );
        head = head->next;
    }
    printf( "\n" );
}

void listFree( node* head ){
    if ( NULL == head ) return;

    if ( NULL != head->next)
    {
        listFree( head->next );
    }

    free(head);
}

node* delByData( node* head, int d){
    if(NULL == head) return NULL;
    node *n,*p;
    n=head;
    while( d != n->data && NULL != n->next ){
        p = n;
        n = n->next;
    }

    if ( d == n->data )
    {
        if ( n == head )
        {
            head = head->next;
            free(n);
        }else {
            p->next = n->next;
            free(n);
        }
    }else{
        printf("del tgt not found\n");
    }
    return head;
}

node* insert( node* head, int d){
    if(NULL == head) return NULL;
    node *n,*p;
    node *newnode = (node* ) malloc( sizeof( node ));
    newnode->data = d;

    n = head;
    while( n->data < d && n->next != NULL ){
        p = n;
        n = n->next;
    }

    if ( n->data >= d)
    {
        if ( n == head)
        {
            newnode->next = n;
            head = newnode;
        }else{
            newnode->next = n;
            p->next = newnode;
        }
    }else //n->data < d
    {
        newnode->next = NULL;
        n->next = newnode;
    }  

    return head;
}

node* selSort( node *head ){
    if ( NULL == head || NULL == head->next)
        return head;
    node *m,*n;

    m = head;
    n = head->next;
    while( NULL != n){
        printf("ss- ");
        listPrint( head );
        while( NULL != n){
            if ( n->data < m->data)
            {
                int tmp = n->data;
                n->data = m->data;
                m->data = tmp;
            }
            n = n->next;
        }
        m = m->next;
        n = m->next;
    }
    return head;
}

node* bubbleSort( node *head){
    if ( NULL == head || NULL == head->next)
        return head;

    node *m, *n;
    int flag, len = listLen(head);
    int j,i = len -1;
    while( i > 0  ){
        printf("bs- ");
        listPrint( head );
        m = head;
        n = head->next;
        flag = 0;
        for( j= 0 ; j < i; ++j  ) {
            if ( n->data < m->data)
            {
                int tmp = n->data;
                n->data = m->data;
                m->data = tmp;
                flag = 1;
            }
            m = m->next;
            n = n->next;
        }
        if( 0 == flag )
            break;
        --i;
    }
    return head;
}

node* reverse(node * head){
    if ( NULL == head || NULL == head->next)
        return head;

    node *p, *n, *nn;
    p = head;
    n = head->next;
    head->next = NULL;
    while( NULL != n ){
        nn = n->next;
        n->next = p; //reverse

        p = n;
        n = nn;
    }
    return p;
}

int main()
{
    //new a new list
    node *p,*head;
    int d,deld,insertd;

    p = head = NULL;
    while( scanf("%d",&d) )
    {
        if( 0 == d ) break;
        node *n = (node*) malloc(sizeof(node));
        n->data = d;
        n->next = NULL;
        if (NULL == head)
            p = head = n;
        p->next = n;
        p = n;
    }

    listLen( head );
    listPrint( head );

    printf("del?");
    scanf("%d",&deld);
    head = delByData(head, deld);
    listPrint( head );

    printf("insert?");
    scanf("%d",&insertd);
    head = insert(head, insertd);
    listPrint( head );

    printf("reverse\n");
    head = reverse (head );
    listPrint( head );

    printf("sort\n");
    //head = selSort( head );
    head = bubbleSort( head );
    listPrint( head );

    listFree( head );
    return 0;
}

