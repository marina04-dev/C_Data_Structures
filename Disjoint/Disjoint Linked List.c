#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h> // sos: external library

#define FALSE 0;
#define TRUE 1;


struct extended_list {
    LIST_PTR head;
    LIST_PTR last;
};

typedef struct extended_list EXTENDED_LIST;

struct disjoint {
    elem *repr; // representatives array  
    EXTENDED_LIST *list; // lists array 
    int N; // amount of elements
};

typedef struct disjoint DISJOINT;


// Basic Calculations For Disjoint Sets 
void DS_init(DISJOINT *d, int N);
void DS_make_set(DISJOINT *d, elem x);
int DS_union(DISJOINT *d, elem x, elem y);
elem DS_find_set(DISJOINT d, elem  x);
void DS_destroy(DISJOINT *d);

// Alternative Calculations For Disjoint Sets 
void DS_print(DISJOINT d);

int main() {
    
}

void DS_init(DISJOINT *d, int N) {
    int i;
    d->N = N;
    d->repr = (elem *)malloc(sizeof(elem)*N);
    if (!d->repr) {
        printf("Error Allocating Memory!");
        exit(0);
    }
    d->list = (EXTENDED_LIST *)malloc(sizeof(EXTENDED_LIST)*N);
    if (!d->list) {
        printf("Error Allocating Memory!");
        exit(0);
    }
    for (i=0; i<N; i++) {
        d->list[i].head=NULL;
        d->list[i].last=NULL;
    }
    for (i=0; i<N; i++) {
        DS_make_set(d,i);
        d->repr[i]=i;
    }
}

void DS_make_set(DISJOINT *d, elem x) {
    LL_insert_start(&((d->list[x]).head),x);
    d->list[x].last=d->list[x].head;
}

elem DS_find_set(DISJOINT d, elem x) {
    return d.repr[x];
}

int DS_union(DISJOINT *d, elem x, elem y) {
    LIST_PTR current;
    if (d->repr[x]==d->repr[y]) {
        printf("Error: Both Elements In The Same Set");
        return FALSE;
    }
    d->list[x].last->next=d->list[y].head;
    d->list[x].last = d->list[y].last;
    
    current = d->list[x].head;
    while (current!=NULL) {
        d->list[current->data]=d->list[x];
        current=current->next;
    }
    current=d->list[y].head;
    while (current!=NULL) {
        d->repr[current->data]=x;
        d->list[current->data]=d->list[x];
        current=current->next;
    }
    return TRUE;
}

elem DS_find_set(DISJOINT d, elem x) {
    return d.repr[x];
}

void DS_destroy(DISJOINT *d) {
    int i;
    LIST_PTR current;
    elem x;

    for (i=0; i<d->N; i++) {
        current = d->list[i].head;
        while(current!=NULL) {
            d->list[current->data].head=NULL;
            LL_delete_start(&current, &x);
        }
    }

    free(d->list);
    free(d->repr);
}

/* Alternative Calculations */
void DS_print(DISJOINT d) {
    int i;
    int *MARK;
    LIST_PTR current, head;

    MARK=(int *)malloc(sizeof(int)*d.N);
    for (i=0; i<d.N; i++)
        MARK[i]=0;

    for (i=0; i<d.N; i++) {
        head = d.list[i].head;
        current = head;
        if (MARK[current->data]==1)
            continue;

        printf("{ ");
        while(current!=NULL) {
            printf("%d ",current->data);
            MARK[current->data]=1;
            current = current->next;
        }
        printf("}\n");
    }
    free(MARK);
}
