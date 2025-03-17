#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
    
typedef int elem;

struct node {
    elem data;
    struct node *next;
    struct node *prev;
};

typedef struct node LIST_NODE;
typedef struct node *LIST_PTR;

void DLL_init(LIST_PTR *head);
int DLL_empty(LIST_PTR head);
elem DLL_data(LIST_PTR p);
int DLL_insert_start(LIST_PTR *head, elem x);
int DLL_insert_after(LIST_PTR p, elem x);
int DLL_delete_start(LIST_PTR *head, elem *x);
int DLL_delete_after(LIST_PTR prev, elem *x);
void DLL_destroy(LIST_PTR *head);
void DLL_print(LIST_PTR head);


int main() {
    int elem;
	LIST_PTR head,prev,current;
	
	DLL_init(&head);
	
	/* Insert "1" */
	DLL_insert_start(&head, 1);
	
	printf("\n");
	DLL_print(head);
	
	/* Insert "2" at the begining */
	DLL_insert_start(&head, 2);
	
	printf("\n");
	DLL_print(head);
	
	/* Insert "3" after the 1st element */
	DLL_insert_after(head, 3);
	
	printf("\n");
	DLL_print(head);
	
	/* Insert "4" after the 2nd element */
	DLL_insert_after(head->next, 4);
	
	printf("\n");
	DLL_print(head);
	
	/* Insert "5" at the begining */
	DLL_insert_start(&head, 5);
	
	printf("\n");
	DLL_print(head);
	
	/* Insert "6" at the begining */
	DLL_insert_start(&head, 6);
	
	printf("\n");
	DLL_print(head);
	
	/* Insert "4" at the end */
	current=head;
	prev=current;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	DLL_insert_after(prev, 7);

	printf("\n");
	DLL_print(head);

	/* Deletion of the 1st element */
	DLL_delete_start(&head,&elem);
	
	printf("\n");
	DLL_print(head);

	/*  Deletion of the last element*/
	current=head;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	DLL_delete_after(prev,&elem);
	
	printf("\n");
	DLL_print(head);

	DLL_destroy(&head);
}

// DLL_init(): initializes the double linked list
void DLL_init(LIST_PTR *head) {
    *head = NULL;
}

// DLL_empty(): returns TRUE if double linked list is empty else returns FALSE 
int DLL_empty(LIST_PTR head) {
    return head == NULL;
}

// DLL_data(): returns the data of node p 
elem DLL_data(LIST_PTR p) {
    return p->data;
}

// DLL_insert_start(): Enters element x at the start of our linked list 
int DLL_insert_start(LIST_PTR *head, elem x) {
    LIST_PTR newnode;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->next=*head;
    newnode->prev=NULL;
    *head=newnode;
    if (newnode->next!=NULL) {
        newnode->next->prev=newnode;
    }
    return TRUE;
}

// DLL_insert_after(): Enters element x after element p 
int DLL_insert_after(LIST_PTR p, elem x) {
    LIST_PTR newnode;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->next=p->next;
    newnode->prev=p;
    p->next=newnode;
    if (newnode->next!=NULL) {
        newnode->next->prev=newnode;
    }
    return TRUE;
}

// DLL_delete_start(): Deletes element x at the start of our linked list 
int DLL_delete_start(LIST_PTR *head, elem *x) {
    LIST_PTR current;
    if (*head==NULL) {
        return FALSE;
    }
    current=*head;
    *x=current->data;
    (*head)=(*head)->next;
    if ((*head) != NULL) {
        (*head)->prev=NULL;
    }
    free(current);
    return TRUE;
}

// DLL_delete_after(): Deletes element x after element p 
int DLL_delete_after(LIST_PTR prev, elem *x) {
    LIST_PTR current;
    if (prev->next==NULL) {
        return FALSE;
    }
    current=prev->next;
    *x=current->data;
    prev->next=current->next;
    if (current->next!=NULL) {
        current->next->prev=prev;
    }
    free(current);
    return TRUE;
}

// DLL_destroy(): Memory Release
void DLL_destroy(LIST_PTR *head) {
    LIST_PTR ptr;
    while (*head!=NULL) {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}

// DLL_print(): Prints a double linked list's elements 
void DLL_print(LIST_PTR head) {
    LIST_PTR current;
    current=head;
    while (current!=NULL) {
        printf("%d ", current->data);
        current=current->next;
    }
}
