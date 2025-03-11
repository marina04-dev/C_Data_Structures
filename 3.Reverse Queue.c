#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE 10 // stack's size
typedef int elem; // stack's items data type 

#define QUEUE_SIZE 10      /* Queue's Array Length */

typedef int elem;          /* Queue's data type */

struct Stack {
    elem array[SIZE]; // array with items
    int top; // top of the stack
};

struct queue{
   elem array[QUEUE_SIZE]; /* elements array     */
   int start;			   /* queue's start		*/
   int finish;             /* queue's end     */
};

typedef struct queue QUEUE; /* queue's struct alias */
typedef struct Stack STACK; // Struct Stack's Alias 

void st_init(STACK *s); // initializes the stack's top to -1
int st_empty(STACK s); // returns true if stack ie empt
int st_full(STACK s); // returns true if stack is full 
int st_push(STACK *s, elem x); // pushes an item to the top if stack is not full
int st_pop(STACK *s, elem *x); // pops an item of the top if stack is not empty


void QU_init(QUEUE *s);
int QU_empty(QUEUE s);
int QU_full(QUEUE s);
int QU_enqueue(QUEUE *s, elem x);
int QU_dequeue(QUEUE *s, elem *x);
void QU_print(QUEUE *q);
void QU_reverse(QUEUE *q);

int main()
{
	int choice,elem,i;
	QUEUE q;
	
	QU_init(&q);
	
	while(1)
	{
		system("cls");
		printf("Queue Menu: ");
		printf("\n--------------");
		printf("\n1-Add Element");
		printf("\n2-Remove Element");
		printf("\n3-Queue Print");
		printf("\n4-Queue Reverse");
		printf("\n5-Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the Element: ");
				scanf("%d",&elem);
				if (QU_enqueue(&q,elem))
					printf("Add fullfilled with success!");
				else
					printf("Add Cannot Be Done! Full Queue!");
				break;
			case 2:
				if (QU_dequeue(&q,&elem))
					printf("Remove fullfilled with success!");
				else
					printf("Removal Cannot Be Done! Empty Queue!");
				break;
			case 3:
				QU_print(&q);
				break;
			case 4:
				QU_reverse(&q);
				break;
			case 5:
				printf("Exit!");
				exit(0);
			default:
				printf("Wrong Input!");
		}
		printf("\n\n");
		system("pause");
	}
}

void st_init(STACK *s) {
    s->top=-1;
}

int st_empty(STACK s) { 
    return s.top==-1;
}

int st_full(STACK s) { 
    return s.top==SIZE-1;
}

int st_push(STACK *s, elem x) {
    if (st_full(*s)) {
        return FALSE;
    }
    else {
        s->top++;
        s->array[s->top]=x;
        return TRUE;
    }
}

int st_pop(STACK *s, elem *x) {
    if (st_empty(*s)) {
        return FALSE;
    }
    else {
        *x=s->array[s->top];
        s->top--;
        return TRUE;
    }
}

/* QU_init(): initializes queue */
void QU_init(QUEUE *q)
{
	q->start =-1;
	q->finish=-1;
}

/* QU_empty(): returns TRUE/FALSE
 *          depending if queue is empty or not */
int QU_empty(QUEUE q)
{
	return q.start==-1;
}

/* QU_full(): returns TRUE/FALSE
 *          depending if queue is full or not */
int QU_full(QUEUE q)
{
	return q.start==(q.finish+1)%QUEUE_SIZE;
}

/* QU_enqueue(): Adds x on queue q
*	returns TRUE: in case of success
*		 FALSE: in case of failure */
int QU_enqueue(QUEUE *q,elem x)
{
	if (QU_full(*q))
		return FALSE;
	else
	{
		if (QU_empty(*q))
		{
			q->start=0;
			q->finish=0;
		}
		else
		{
			q->finish=(q->finish+1)%QUEUE_SIZE;
		}
		q->array[q->finish]=x;
		return TRUE;
	} 
}


/* QU_dequeue(): Removes the first item of the queue
*	returns TRUE: in case of success
*		 FALSE: in case of failure */
int QU_dequeue(QUEUE *q,elem *x)
{
	if (QU_empty(*q))
		return FALSE;
	else
	{
		*x=q->array[q->start];
		
		if (q->start == q->finish) /* H oura adeiase */
		{
			q->start=-1;
			q->finish=-1;
		}
		else
		{
			q->start=(q->start+1)%QUEUE_SIZE;	
		}

		return TRUE;
	}
}

void QU_print(QUEUE *q)
{
	QUEUE temp;
	int x;
	
	/* 1. Queue's Elements Print*/
	QU_init(&temp);
	
	while(!QU_empty(*q))
	{
		QU_dequeue(q,&x);
		printf("%3d|",x);
		QU_enqueue(&temp,x);
	}
	
	/* 2. Refill queue q */
	
	while (!QU_empty(temp))
	{
		QU_dequeue(&temp,&x);
		QU_enqueue(q,x);
	}
}

void QU_reverse(QUEUE *q) {
    STACK temp;
    int x;
    st_init(&temp);
    // 1. Emptying queue and filling stack
    while (!QU_empty(*q)) {
        QU_dequeue(q, &x);
        st_push(&temp,x);
    }
    
    // 2. Emptying stack and filling queue
    while (!st_empty(temp)) {
        st_pop(&temp, &x);
        QU_enqueue(q,x);
    }
}
