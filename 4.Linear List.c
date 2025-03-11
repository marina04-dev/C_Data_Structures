#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 
#define TRUE 1
#define FALSE 0 

typedef int elem; // list's elements data type 
typedef struct list LIST; // list's struct alias

struct list {
    elem data[SIZE]; // data array 
    int N; // amount of data 
};

void SL_init(LIST *l);
int SL_empty(LIST l);
elem SL_data(LIST l, int ind);
int SL_insert(LIST *l, int ind, elem x);
int SL_delete(LIST *l, int ind, elem *x);

int main() {
    
}


// SL_init(): initializes the list 
void SL_init(LIST *l) {
    l->N=0;
}


// SL_empty(): returns TRUE/FALSE if list is empty 
int SL_empty(LIST l) {
    return l.n==0;
}

// SL_data(): returns data of node with index ind 
elem SL_data(LIST l, int ind) {
    return l.data[ind];
}

// SL_insert(): Enters x in ind 
int SL_insert(LIST *l, int ind, elem x) {
    int i;
    if (ind<0 || ind>l->N) {
        return FALSE;
    }
    if (l->N < SIZE) {
        for (i=l->N; i>ind; i--) {
            l->data[i]=l->data[i-1];
        }
        
        l->data[ind]=x;
        l->N++;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// SL_delete(): Deletes data that is in index ind 
int SL_delete(LIST *l, int ind, elem *x) {
    int i;
    if (ind<0 || ind>=l->N) {
        return FALSE;
    }
    *x=l->data[ind];
    for (i=ind; i<l->N; i++) {
        l->data[i]=l->data[i+1];
    }
    l->N--;
    return TRUE;
}
