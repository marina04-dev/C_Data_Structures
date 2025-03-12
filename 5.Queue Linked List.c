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

struct queue{
	LIST_PTR start; 
	LIST_PTR end; 
};

typedef struct queue QUEUE; 

void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
elem LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head,elem x);
int LL_insert_after(LIST_PTR p,elem x);
int LL_delete_start(LIST_PTR *head, elem *x);
int LL_delete_after(LIST_PTR prev, elem *x);
void LL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

void QU_init(QUEUE *q);
int QU_empty(QUEUE q);
int QU_enqueue(QUEUE *q,elem x);
int QU_dequeue(QUEUE *q,elem *x);
int QU_destroy(QUEUE q);

int main() {
    QUEUE q; 
	elem x; 
	
	QU_init(&q);
	
	QU_enqueue(&q, 1);
	QU_enqueue(&q, 2);
	
	QU_dequeue(&q, &x);
	printf("%d", x);
	QU_dequeue(&q, &x);
	printf("%d", x);
	
	QU_destroy(q);
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
		printf("Adynamia desmeusis mnimis");
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
		printf("Adynamia desmeusis mnimis");
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
	while(current!=NULL) {
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

void QU_init(QUEUE *q) {
	q->start=NULL;
	q->end=NULL; 
}

int QU_empty(QUEUE q) {
	if (q.start==NULL)
		return TRUE;
	return FALSE; 
}

int QU_enqueue(QUEUE *q,elem x) {
	int ret; 
	if (q->start==NULL) {
		ret=LL_insert_start(&(q->start), x);
		if (ret==TRUE) {
			q->end=q->start;
			return TRUE; 	
		}
		else return FALSE; 
	}
	else {
		ret=LL_insert_after(q->end, x);
		if (ret=TRUE) {
			q->end=q->end->next; 
			return TRUE;	
		}
		else return FALSE; 
	}
}

int QU_dequeue(QUEUE *q,elem *x) {
	if (q->start==NULL) {
		return FALSE; 
	}
	else if (q->start==q->end) {
		LL_delete_start(&(q->start), x);
		q->start=NULL;
		q->end=NULL; 
	}
	else {
		LL_delete_start(&(q->start), x);
	}
	return TRUE;
}

int QU_destroy(QUEUE q) {
	LL_destroy(&(q.start));
}
