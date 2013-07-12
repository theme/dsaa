/*
 * Implementation of linked list.( has header node )
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
	Position Next;
};

List makeEmpty( List L ){
	PtrToNode p,tmp;
	p = L->Next;
	while( NULL != p ){
		tmp = p->Next;
		free(p);
		p = tmp;
	}
	L->Next = NULL;
	return L;
}

int isEmpty( List L ){
	return NULL == L->Next ;
}

int isLast( Position P, List L ){
	return NULL == P->Next ;
}

Position findNode( ElementType X, List L ){
	Position P;
	P = L->Next;
        
	while( NULL != P && P->data!= X)
		P = P->Next;

	return P;
}

Position findPreviousNode( ElementType X, List L){
	Position P;
	P = L;

	while( NULL != P->Next && P->Next->data != X )
		P = P->Next;

	return P;
}

void delNode( ElementType X, List L ){
	Position P;
	P = findPreviousNode( X, L );
	if( !isLast( P, L ) ){
		Position tmp = P->Next;
		P->Next = tmp->Next;
		free( tmp );
	}
}

void insertAfter( ElementType X, List L, Position P ){
	Position newnode = malloc( sizeof(struct Node));
	if( NULL == newnode )
		return;
	newnode->data = X;
	newnode->Next = P->Next;
	P->Next = newnode;
}

void insertBefore( ElementType X, List L, Position P ){
	Position pn = findPreviousNode( P->data, L );
	Position newnode = malloc( sizeof(struct Node));
	if( NULL == newnode )
		return;
	newnode->data = X;
	newnode->Next = P;
	pn->Next = newnode;
}

void deleteList( List L ){
        makeEmpty( L );
        free(L);
}

Position header( List L ){
        return L;
} 

Position first( List L ){
        return L->Next;
}

Position advance( Position P){
        return P->Next;
}

ElementType retrieve( Position P ){
        return P->data;
}

void printList( List L){
	while( NULL != L->Next ){
		printf("%d ", L->Next->data);
		L = L->Next;
	}
	printf("\n");
}

void bubbleSort( List L, int s){
    int i,j;
    Position p;

    i = 0;
    for( i=0; i<s; i++ ){
        p = L->Next;
        if (NULL == p)
            return;

        for( j=0; j<s-i; j++ ){
            if ( NULL == p || NULL == p->Next )
                break;

            if( p->data > p->Next->data){
                ElementType tmp = p->Next->data;
                p->Next->data = p->data;
                p->data = tmp;
            }
            p = p->Next;
        }
    }
}

void swapNext(Position p, List l ){
        Position prev;
        Position n = p->Next;
        if ( NULL == n)
                return;
        prev = findPreviousNode( p->data, l );

        prev->Next = n;
        p->Next = n->Next;
        n->Next = p;
}

/* remove duplicated data nodes */
void removeDup( List l ){
        Position  n, p;
        p = first( l ) ;
        while ( NULL != p ){
                n = p->Next;
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
        L = L->Next;
        P = P->Next;
        while ( NULL != P && NULL != L){
                //printf("i%d ",i );
                if ( P->data == i){
                        printf("L%d = %d \n", i, L->data );
                        if (NULL != P->Next && P->Next->data == i){
                                P = P->Next;
                                continue;
                        }
                        P = P->Next;
                }
                L = L->Next;
                i++;
        }
}

/* print intersections of two list */
void intersectionList( List l, List p){
        l = l->Next;
        p = p->Next;
        printf("intersction\t" );
        while ( NULL != l && NULL != p)
        {
                if ( l->data == p->data){
                        printf("%d ", l->data);
                        l = l->Next;
                        p = p->Next;
                }else if (l->data < p->data)
                {
                        l = l->Next;
                }else{ //l->data > p->data
                        p = p->Next;
                }
        }
        printf("\n");
}

/* print union of two list */
void unionList( List l, List p){
        l = l->Next;
        p = p->Next;
        printf("union \t" );
        while ( NULL != l && NULL != p){
                if ( l->data == p->data){
                        printf("%d ", l->data);
                        p = p->Next;
                        l = l->Next;
                }else if ( l->data < p->data){
                        printf("%d ", l->data);
                        l = l->Next;
                }else{ // l->data > p->data
                        printf("%d ", p->data);
                        p = p->Next;
                }
        }
        if ( NULL != l )
        {
                while ( NULL != l)
                {
                        printf("%d ", l->data);
                        l = l->Next;
                }
        }
        if ( NULL != p)
        {
                while ( NULL != p)
                {
                        printf("%d ", p->data);
                        p = p->Next;
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

