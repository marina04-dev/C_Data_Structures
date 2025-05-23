#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	LIST_PTR first;
	LIST_PTR last;
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
void QU_enqueue(QUEUE *q, elem x);
int QU_dequeue(QUEUE *q, elem *x);
void QU_print(QUEUE q);
void QU_destroy(QUEUE q);


int main() {
	QUEUE q;
	elem x;
	int i;

	srand(time(NULL));
	QU_init(&q);

	for (i=0; i<400; i++) {
        if (rand()%2) {
            printf("enqueue.. ");
            x = rand()%100;
            QU_enqueue(&q, x);
        }
        else {
            printf("dequeue .. ");
            QU_dequeue(&q, &x);
        }
        QU_print(q);
        printf("\n");
    }

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
	q->first = NULL;
	q->last = NULL;
}

int QU_empty(QUEUE q) {
	return LL_empty(q.first);
}

void QU_enqueue(QUEUE *q,elem x) {
	if (LL_empty(q->first)) {
		LL_insert_start(&(q->first),x);
		q->last = q->first;
	}
	else {
		LL_insert_after(q->last, x);
		q->last = q->last->next;
	}
}


int QU_dequeue(QUEUE *q,elem *x) {
	if (QU_empty(*q)) {
		printf("No pop. Queue is empty!");
		return FALSE;
	}
	else {
		LL_delete_start(&(q->first), x);
		if(QU_empty(*q))
			q->last=NULL;
		return TRUE;
	}
}

void QU_print(QUEUE q) {
	LL_print(q.first);
}

void QU_destroy(QUEUE q) {
	LL_destroy(&q.first);
}
