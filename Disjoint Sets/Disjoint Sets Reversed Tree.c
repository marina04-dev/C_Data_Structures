#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef int elem;

struct disjoint_node {
    elem data;
    int height;
    struct disjoint_node *parent;
};

typedef struct disjoint_node DISJOINT_NODE;
typedef struct disjoint_node *DISJOINT_PTR;

struct disjoint {
   DISJOINT_PTR *array; 
   int N;				    /* amount of pointers */
};

typedef struct disjoint DISJOINT;


/* Basic Calculations */
void DS_init(DISJOINT *d, int N);
void DS_make_set(DISJOINT *d, elem x);
int DS_union(DISJOINT *d, elem x, elem y);
elem DS_find_set(DISJOINT d, elem x);
void DS_destroy(DISJOINT *d);

/* Secondary Calculations */
void DS_print(DISJOINT d);


int main()
{
	DISJOINT d;

    DS_init(&d, 7);

    DS_print(d);

    printf("UNION(1,3):\n");
    DS_union(&d, 1, 3);
    DS_print(d);

    printf("UNION(2,4):\n");
    DS_union(&d, 2, 4);
    DS_print(d);

    printf("UNION(2,5):\n");
    DS_union(&d, 2, 5);
    DS_print(d);

    printf("UNION(3,5):\n");
    DS_union(&d, 3, 5);
    DS_print(d);

    DS_destroy(&d);

	return 0;
}


/* Basic Calculations */
void DS_init(DISJOINT *d, int N) {
    int i;

    d->N = N;

    d->array = (DISJOINT_PTR *)malloc(sizeof(DISJOINT_PTR)*N);
    if (!d->array) {
        printf("Error allocating memory!");
        exit(0);
    }

    for (i=0; i<N; i++)
        DS_make_set(d, i);

}

void DS_make_set(DISJOINT *d, elem x) {
    d->array[x] = (DISJOINT_NODE *)malloc(sizeof(DISJOINT_NODE));
    if (!d->array[x]) {
        printf("Error allocating memory!");
        exit(0);
    }
    d->array[x]->data = x;
    d->array[x]->height = 0;
    d->array[x]->parent = d->array[x];
}

int DS_union(DISJOINT *d, elem x, elem y) {
    int p1, p2;

    p1 = DS_find_set(*d, x);
    p2 = DS_find_set(*d, y);

    if (p1==p2) {
        printf("Elements %d and %d are in the same set(%d)", x, y, p1);
        return FALSE;
    }

    if (d->array[p1]->height < d->array[p2]->height)
        d->array[p1]->parent = d->array[p2];
    else if (d->array[p1]->height > d->array[p2]->height)
        d->array[p2]->parent = d->array[p1];
    else {
        d->array[p2]->parent = d->array[p1];
        (d->array[p1]->height)++;
    }

    return TRUE;
}

elem DS_find_set(DISJOINT d, elem x) {
    int p;
    if (d.array[x]->parent == d.array[x])
        return x;
    else {
        p = DS_find_set(d, d.array[x]->parent->data);
        d.array[x]->parent=d.array[p];
        return p;
    }
}

void DS_destroy(DISJOINT *d) {
    int i;

    for (i=0; i<d->N; i++) {
        free(d->array[i]);
    }

    free(d->array);
}

/* Secondary Calculations */
void DS_print(DISJOINT d) {
    int i;

    for (i=0; i<d.N; i++) {
        printf("%d->%d (set: %d)\n", i, d.array[i]->parent->data, DS_find_set(d,i));
    }
}
