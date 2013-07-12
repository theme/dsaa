#include "list.h"

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

        deleteList( li );
        deleteList( lp );

	return 0;
}
