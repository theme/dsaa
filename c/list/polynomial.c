/*
 * Implementation of polynomial
 * using double linked list.( has header node )
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "poly.h"

#define LSIZE 10

struct  Node
{
        int coeff;
	int exp;
	Position next;
        Position prev;
};

Poly makeEmpty( Poly L ){
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

int isEmpty( Poly L ){
	return NULL == L->next ;
}

int isLast( Position P, Poly L ){
	return NULL == P->next ;
}

Position findNode( int X, Poly L ){
	Position P;
	P = L->next;
        
	while( NULL != P && P->exp!= X)
		P = P->next;

	return P;
}

Position findPreviousNode( int X, Poly L){
	Position P;
	P = L;

	while( NULL != P->next && P->next->exp > X )
		P = P->next;

	return P;
}

void delNode( int X, Poly L ){
	Position b, p, n;
	b = findPreviousNode( X, L );
	if( !isLast( b, L ) && b->next->exp != X){
		p = b->next;
                n = p->next;
                
		b->next = n;
                if ( NULL != n )
                        n->prev = b;
                
		free(p);
	}
}


void insertAfter( int coeff, int exp, Poly L, Position P ){
	Position n = P->next;
	Position newnode = malloc( sizeof(struct Node));
	if( NULL == newnode )
		return;
	newnode->coeff = coeff;
	newnode->exp = exp;
	newnode->next = n;
        newnode->prev = P;

        if ( NULL != n)
                n->prev = newnode;
	P->next = newnode;
}

void insertBefore( int coeff, int exp, Poly L, Position P ){
	Position prev = P->prev;
	Position newnode = malloc( sizeof(struct Node));
	if( NULL == newnode )
		return;
	newnode->coeff = coeff;
	newnode->exp = exp;
	newnode->next = P;
        newnode->prev = prev;
	prev->next = newnode;
        P->prev = newnode;
}

void deletePoly( Poly L ){
        makeEmpty( L );
        free(L);
}

Position header( Poly L ){
        return L;
} 

Position first( Poly L ){
        return L->next;
}

Position advance( Position P){
        return P->next;
}

int retrieve( Position P ){
        return P->exp;
}

void printPoly( Poly L){
	while( NULL != L->next ){
		printf("%dx^%d ", L->next->coeff, L->next->exp);
		L = L->next;
	}
	printf("\n");
}

void swapNext(Position p, Poly l ){
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

/* remove duplicated exp nodes */
void removeDup( Poly l ){
        Position  n, p;
        p = first( l ) ;
        while ( NULL != p ){
                n = p->next;
                if ( NULL != n && p->exp == n->exp )
                {
                        p->coeff += n->coeff;
                        delNode( p->exp, l);
                }
                p = n;
        }
}

Poly newPoly(){
        Poly po = (Poly) malloc( sizeof(struct Node));
        return po;
}

void addItem( int coeff, int exp, Poly L ){
        Position p = findPreviousNode( exp, L );
        if( !isLast(p,L) && p->next->exp == exp )
                p->next->coeff += coeff;
        else
                insertAfter( coeff, exp, L, p);

}

Poly polyAdd( Poly A, Poly B){
        Poly sum = newPoly();
        Position a = first( A );
        while ( NULL != a)
        {
                addItem( a->coeff, a->exp, sum);
                a = a->next;
        }
        
        a = first( B );
        while ( NULL != a)
        {
                addItem( a->coeff, a->exp, sum);
                a = a->next;
        }
        return sum;
}

int
polyLen( Poly P){
        int len = 0;
        while ( NULL != P )
        {
                len ++;
                P = P->next;
        }
        return len;
}

Poly
polyMultiply2( Poly A, Poly B){
        Poly l = newPoly();
        if (NULL == l)
                return l;

        Position a = first( A );
        while ( NULL != a)
        {
                Position b = first( B );
                Position pl = l; 

                while (NULL != b)
                {
                        int exp = a->exp * b->exp;
                        while ( NULL != pl->next && pl->next->exp > exp)        //start position for this round of insertion
                                pl  = pl->next;

                        if ( NULL != pl->next && pl->next->exp == exp)
                                pl->next->coeff += a->coeff * b->coeff;
                        else
                                insertAfter( a->coeff * b->coeff, exp, l, pl);

                        b = b->next;
                }
                a = a->next;
        }
        return l;
}

Poly
polyMultiply( Poly A, Poly B){
        Poly l = newPoly();
        if (NULL == l)
                return l;

        Position a = first( A );
        while ( NULL != a)
        {
                Position b = first( B );
                while (NULL != b)
                {
                        addItem( a->coeff * b->coeff, a->exp + b->exp, l);
                        b = b->next;
                }
                a = a->next;
        }
        return l;
}

Poly
polyOne(){
        Poly one = newPoly();
        addItem( 1, 0, one );
        return one;
}

/* calculate exponent of polynomial */
Poly
polyExp( Poly p, int e ){
        if ( 0 == e)
                return polyOne();
        if ( 1 == e )
                return p;
        if ( 0 == e % 2) //todo isEven()
        {
                return polyExp( polyMultiply( p, p) , e/2 );
        }else
        {
                return polyMultiply( polyExp( polyMultiply( p, p) , e/2 ), p );
        }
}

int main(int argc, char const *argv[]){
        int i,a,b;
        int tmp;
        Poly li, lp, mulp, sump;
        li = newPoly();
        lp = newPoly();

        if ( NULL == li || NULL == lp)
                return 1;
        li->exp = 0;
        lp->exp = 0;

        srand( time(NULL) );
	for(i = 0 ; i< LSIZE; i++){
                a = rand()/(RAND_MAX/LSIZE);
                b = rand()/(RAND_MAX/LSIZE);
                addItem( a, b, li);
                addItem( b, a, lp);
	}

        //removeDup( li);
        //removeDup( lp);

        printPoly( li );
        printPoly( lp );

        mulp = polyMultiply2( li, lp);
        printf("\nmultiply : " );
        printPoly( mulp );
        deletePoly( mulp);

        sump = polyAdd( li, lp);
        printf("\nadd : " );
        printPoly( sump );
        deletePoly( sump );

        printf("\n li ^2: ");
        printPoly( polyExp(li,2) );

        //swapNext( first(li), li );
        deletePoly( li );
        deletePoly( lp );

	return 0;
}

