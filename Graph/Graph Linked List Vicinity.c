#include <stdio.h>
#include <stdlib.h>
typedef int elem; // list's elements Data type

struct node { 
    elem data;
    struct node *next;
};

// aliases 
typedef struct node LIST_NODE;
typedef struct node *LIST_PTR;


void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
elem LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head, elem x);
int LL_insert_after(LIST_PTR p, elem x);
int LL_delete_start(LIST_PTR *head, elem *x);
int LL_delete_after(LIST_PTR prev, elem *x);
void LL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

struct graph {
   LIST_PTR *array;	     	/* Array Of Vicinity List */
   int N;				    /* Nodes Amount */
};

typedef struct graph GRAPH;

/* Basic Calculations */
void GR_init(GRAPH *g, int N);
void GR_print(GRAPH g);
void GR_destroy(GRAPH g);

/* Secondary Calculations */
void GR_init_from_file(GRAPH *g, char *filename);


int main() {
	GRAPH g;

	GR_init_from_file(&g, "graph1.graph");
	GR_print(g);

	GR_destroy(g);

	return 0;
}



// LL_init(): initializes the list
void LL_init(LIST_PTR *head) {
    *head = NULL;
}

// LL_empty(): returns TRUE if list is empty and false either
int LL_empty(LIST_PTR head) {
    return head == NULL;
}

// LL_data(): returns the node's data of pointer p 
elem LL_data(LIST_PTR p) {
    return p->data;
}

// LL_insert_start(): Enters element x at the start of our linked list 
int LL_insert_start(LIST_PTR *head, elem x) {
    LIST_PTR newnode;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
    return TRUE;
}

// LL_insert_after(): Enters element x after element p 
int LL_insert_after(LIST_PTR p, elem x) {
    LIST_PTR newnode;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->next=p->next;
    p->next=newnode;
    return TRUE;
}

// LL_delete_start(): Deletes element x at the start of our linked list 
int LL_delete_start(LIST_PTR *head, elem *x) {
    LIST_PTR current;
    if (*head==NULL) {
        return FALSE;
    }
    current=*head;
    *x=current->data;
    (*head)=(*head)->next;
    free(current);
    return TRUE;
}

// LL_delete_after(): Deletes element x after element p 
int LL_delete_after(LIST_PTR prev, elem *x) {
    LIST_PTR current;
    if (prev->next==NULL) {
        return FALSE;
    }
    current=prev->next;
    *x=current->data;
    prev->next=current->next;
    free(current);
    return TRUE;
}

// LL_destroy(): Memory Release
void LL_destroy(LIST PTR *head) {
    LIST_PTR ptr;
    while (*head!=NULL) {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}

// LL_print(): Prints a linked list's elements 
void LL_print(LIST_PTR head) {
    LIST_PTR current;
    current=head;
    while (current!=NULL) {
        printf("%d ", current->data);
        current=current->next;
    }
}

/* GR_init(): initializes the graph */
void GR_init(GRAPH *g, int N)
{
	int i;
	g->N = N;

	g->array = (LIST_PTR *)malloc(sizeof(LIST_PTR)*N);
	if(!g->array)
	{
		printf("Error Allocating Memory");
		exit(0);
	}
	for (i=0; i<N; i++)
		LL_init(&(g->array[i]));

}

/* GR_print(): prints the graph */
void GR_print(GRAPH g) {
	int i;

	for (i=0; i<g.N; i++) {
		printf("%2d: ", i);
		LL_print(g.array[i]);
		printf("\n");
	}
}

/* GR_add_edge(): Edge Addition */
void GR_add_edge(GRAPH g, int vertex1, int vertex2) {
	if (vertex1<0 || vertex1>g.N || vertex2<0 || vertex2>g.N) {
		printf("Error: index out of bounds");
		exit(0);
	}

	LL_insert(&g.array[vertex1], vertex2);
	LL_insert(&g.array[vertex2], vertex1);
}


void GR_destroy(GRAPH g) {
    int i;

    for (i=0; i<g.N; i++) {
        LL_destroy(&g.array[i]);
    }

    free(g.array);
}


/* GR_init_from_file(): initialization from a file */
void GR_init_from_file(GRAPH *g, char *filename) {
	int i,j;
	FILE *fp;

	fp = fopen(filename, "r");
	if (!fp) {
		printf("Error opening file");
		exit(0);
	}
	fscanf(fp,"%d", &g->N);

	g->array = (LIST_PTR *)malloc(sizeof(LIST_PTR)*g->N);
	if(!g->array) {
		printf("Error Allocating Memory");
		exit(0);
	}

	for (i=0; i<g->N; i++)
		LL_init(&(g->array[i]));

	while(!feof(fp)) {
		fscanf(fp,"%d %d", &i, &j);
		GR_add_edge(*g, i, j);
	}

	fclose(fp);
}
