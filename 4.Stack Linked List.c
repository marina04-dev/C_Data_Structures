#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int elem;          

struct node{	
   elem data; 			  
   struct node *next;     
};

typedef struct node LIST_NODE; 
typedef struct node *LIST_PTR; 

typedef LIST_PTR STACK; 

void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
elem LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head,elem x);
int LL_insert_after(LIST_PTR p,elem x);
int LL_delete_start(LIST_PTR *head, elem *x);
int LL_delete_after(LIST_PTR prev, elem *x);
void LL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

void ST_init(STACK *s);
int ST_empty(STACK s);
int ST_push(STACK *s,elem x);
int ST_pop(STACK *s,elem *x);
int ST_print(STACK s);
int ST_destroy(STACK *s);


int main() {
	STACK s; 
	elem x; 
	
	ST_init(&s);
	
	ST_push(&s, 1);
	ST_push(&s, 2);
	ST_push(&s, 3);
	
	ST_print(s);
	
	ST_pop(&s, &x);
	printf("\n\nElement: %d\n", x);
	ST_print(s);
	
	ST_destroy(&s);
}

void LL_init(LIST_PTR *head) {
	*head=NULL;
}

int LL_empty(LIST_PTR head) {
	return head == NULL;
}

elem LL_data(LIST_PTR p) {
	return p->data;
}

int LL_insert_start(LIST_PTR *head,elem x) {
	LIST_PTR newnode;
	
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode) {
		printf("Error Allocating Memory!");
		return FALSE;
	}
	newnode->data=x;

	newnode->next=*head;
	*head=newnode;
	return TRUE;
}

int LL_insert_after(LIST_PTR p,elem x) {
	LIST_PTR newnode;
	
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode) {
		printf("Error Allocating Memory!");
		return FALSE;
	}
	newnode->data=x;
	
	newnode->next=p->next;
	p->next=newnode;
	return TRUE;
}

int LL_delete_start(LIST_PTR *head, elem *x) {
	LIST_PTR current;
	
	if (*head==NULL)
		return FALSE;
		
	current=*head;
	*x=current->data;
	
	(*head)=(*head)->next;
	free(current);
	return TRUE;
}

int LL_delete_after(LIST_PTR prev, elem *x) {
	LIST_PTR current;
	
	if (prev->next==NULL)
		return FALSE;
		
	current=prev->next;
	*x=current->data;
	
	prev->next=current->next;
	free(current);
	return TRUE;
}

void LL_print(LIST_PTR head) {
	LIST_PTR current;
	
	current=head;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
}

void LL_destroy(LIST_PTR *head) {
	LIST_PTR ptr;
	
	while (*head!=NULL) {
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

void ST_init(STACK *s) {
	LL_init(s);
}

int ST_empty(STACK s) {
	return LL_empty(s);
}

int ST_push(STACK *s,elem x) {
	LL_insert_start(s,x);
}

int ST_pop(STACK *s,elem *x) {
	return LL_delete_start(s, x);
}

int ST_print(STACK s) {
	LL_print(s);
}

int ST_destroy(STACK *s) {
	LL_destroy(s);
}
