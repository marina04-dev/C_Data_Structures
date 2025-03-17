#include <stdio.h>
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

int main()
{
  int elem;
	LIST_PTR head,prev,current;
	
	LL_init(&head);
	
	/* Insert "1" */
	LL_insert_start(&head, 1);
	
	printf("\n");
	LL_print(head);
	
	/* Insert "2" at the begining */
	LL_insert_start(&head, 2);
	
	printf("\n");
	LL_print(head);
	
	/* Insert "3" after element 1 */
	LL_insert_after(head, 3);
	
	printf("\n");
	LL_print(head);
	
	/* Insert "4" after element 2 */
	LL_insert_after(head->next, 4);
	
	printf("\n");
	LL_print(head);
	
	/* Insert "5" at the start */
	LL_insert_start(&head, 5);
	
	printf("\n");
	LL_print(head);
	
	/* Insert "6" at the start */
	LL_insert_start(&head, 6);
	
	printf("\n");
	LL_print(head);
	
	/* Insert "7" at the end */
	current=head;
	prev=current;
	while(current->next!=NULL) {
		prev=current;
		current=current->next;
	}
	LL_insert_after(prev, 7);

	printf("\n");
	LL_print(head);

	/* Deletes the 1st element */
	LL_delete_start(&head,&elem);
	
	printf("\n");
	LL_print(head);

	/* Deletes the last element */
	current=head;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	LL_delete_after(prev,&elem);
	
	printf("\n");
	LL_print(head);

	LL_destroy(&head);
  
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
