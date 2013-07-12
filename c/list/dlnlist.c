/*
 * Implementation of double linked list.( has header node )
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;
#include "list.h"

#define LSIZE 10

struct  Node
{
	/* data */
	ElementType data;
	Position next;
        Position prev;
};

List makeEmpty( List L ){
	PtrToNode p,tmp;
	p = L->next;
	while( NULL != p ){
		tmp = p->next;
		free(p);
		p = tmp;
	}
	L->next = NULL;
	return L;
}

int isEmpty( List L ){
	return NULL == L->next ;
}

int isLast( Position P, List L ){
	return NULL == P->next ;
}

Position findNode( ElementType X, List L ){
	Position P;
	P = L->next;
        
	while( NULL != P && P->data!= X)
		P = P->next;

	return P;
}

Position findPreviousNode( ElementType X, List L){
	Position P;
	P = L;

	while( NULL != P->next && P->next->data != X )
		P = P->next;

	return P;
}

void delNode( ElementType X, List L ){
	Position b, p, n;
	b = findPreviousNode( X, L );
	if( !isLast( b, L ) ){
		p = b->next;
                n = p->next;
                
		b->next = n;
                if ( NULL != n )
                        n->prev = b;
                
		free(p);
	}
}

void insertAfter( ElementType X, List L, Position P ){
	Position n = P->next;
	Position newnode = malloc( sizeof(struct Node));
	if( NULL == newnode )
		return;
	newnode->data = X;
	newnode->next = n;
        newnode->prev = P;

        if ( NULL != n)
                n->prev = newnode;
	P->next = newnode;
}

void insertBefore( ElementType X, List L, Position P ){
	Position prev = P->prev;
	Position newnode = malloc( sizeof(struct Node));
	if( NULL == newnode )
		return;
	newnode->data = X;
	newnode->next = P;
        newnode->prev = prev;
	prev->next = newnode;
        P->prev = newnode;
}

void deleteList( List L ){
        makeEmpty( L );
        free(L);
}

Position header( List L ){
        return L;
} 

Position first( List L ){
        return L->next;
}

Position advance( Position P){
        return P->next;
}

ElementType retrieve( Position P ){
        return P->data;
}

void printList( List L){
	while( NULL != L->next ){
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

void swapNext(Position p, List l ){
        Position b, n, nn;
        if (isLast(p,l))
                return;

        n = p->next;
        nn = n->next;
        b = p->prev;

        b->next = n;
        n->prev = b;
        n->next = p;
        p->prev = n;
        p->next = nn;
        if (NULL != nn)
                nn->prev = p;
}

void bubbleSort( List L, int s){
    int i,j;
    Position p;

    i = 0;
    for( i=0; i<s; i++ ){
        p = L->next;
        if (NULL == p)
            return;

        for( j=0; j<s-i; j++ ){
            if ( NULL == p || NULL == p->next )
                break;

            if( p->data > p->next->data){
                    swapNext(p,L);
            }
            p = p->next;
        }
    }
}


/* remove duplicated data nodes */
void removeDup( List l ){
        Position  n, p;
        p = first( l ) ;
        while ( NULL != p ){
                n = p->next;
                if ( NULL != n && p->data == n->data )
                {
                        delNode( p->data, l);
                }
                p = n;
        }
}

/* print items in L at pos specified in P */
void printLots( List L, List P){
        ElementType i = 0;
        L = L->next;
        P = P->next;
        while ( NULL != P && NULL != L){
                //printf("i%d ",i );
                if ( P->data == i){
                        printf("L%d = %d \n", i, L->data );
                        if (NULL != P->next && P->next->data == i){
                                P = P->next;
                                continue;
                        }
                        P = P->next;
                }
                L = L->next;
                i++;
        }
}

/* print intersections of two list */
void intersectionList( List l, List p){
        l = l->next;
        p = p->next;
        printf("intersction\t" );
        while ( NULL != l && NULL != p)
        {
                if ( l->data == p->data){
                        printf("%d ", l->data);
                        l = l->next;
                        p = p->next;
                }else if (l->data < p->data)
                {
                        l = l->next;
                }else{ //l->data > p->data
                        p = p->next;
                }
        }
        printf("\n");
}

/* print union of two list */
void unionList( List l, List p){
        l = l->next;
        p = p->next;
        printf("union \t" );
        while ( NULL != l && NULL != p){
                if ( l->data == p->data){
                        printf("%d ", l->data);
                        p = p->next;
                        l = l->next;
                }else if ( l->data < p->data){
                        printf("%d ", l->data);
                        l = l->next;
                }else{ // l->data > p->data
                        printf("%d ", p->data);
                        p = p->next;
                }
        }
        if ( NULL != l )
        {
                while ( NULL != l)
                {
                        printf("%d ", l->data);
                        l = l->next;
                }
        }
        if ( NULL != p)
        {
                while ( NULL != p)
                {
                        printf("%d ", p->data);
                        p = p->next;
                }
        }
        printf("\n");
}


int main(int argc, char const *argv[]){
        int i;
        int tmp;
        srand( time(NULL) );
	List li = (List) malloc( sizeof(struct Node ));
        li->data = 0;
	List lp = (List) malloc( sizeof(struct Node ));
        lp->data = 0;

	for(i = 0 ; i< LSIZE; i++){
		insertAfter( rand()/(RAND_MAX/LSIZE), li, li);
		insertAfter( rand()/(RAND_MAX/LSIZE), lp, lp);
	}

        bubbleSort( li, LSIZE );
        bubbleSort( lp, LSIZE );

        removeDup( li);
        removeDup( lp);

        printList( li );
        printList( lp );

        printLots( li, lp);
        unionList( li, lp);
        intersectionList( li, lp);

        printList( li);
        swapNext( first(li), li );
        printList( li);
        deleteList( li );
        deleteList( lp );

	return 0;
}

