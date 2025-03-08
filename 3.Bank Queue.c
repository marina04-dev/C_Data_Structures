#include <stdio.h>
#include <stdlib.h>

#define N 8 
#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 5      /* arrays size */

typedef char * elem;          /* queue's data type  */

struct queue{
   elem array[QUEUE_SIZE]; /* elements array   */
   int start;			   /* start of queue 		*/
   int finish;             /* end of queue       */
};

typedef struct queue QUEUE; /* Alias of queue */


void QU_init(QUEUE *s);
int QU_empty(QUEUE s);
int QU_full(QUEUE s);
int QU_enqueue(QUEUE *s, elem x);
int QU_dequeue(QUEUE *s, elem *x);


int main() {
	int choice,i;
	QUEUE tameio1,tameio2;
	char *pelatis;
	
	
	QU_init(&tameio1);
	QU_init(&tameio2);
	
	while(1) {
		system("cls");
		printf("Bank Menu: ");
		printf("\n--------------");
		printf("\n1-Customer Arrival");
		printf("\n2-Customer Exit");
		printf("\n3-Exit");
		printf("\Enter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter Customer's Fullname: ");
				
				pelatis=malloc(sizeof(char)*N);
				if (!pelatis) {
					printf("Error Allocating Memory!");
					exit(0);
				}
				scanf("%s",pelatis);
				
				if (QU_enqueue(&tameio1,pelatis)) {
					printf("Customer %s was added to cash register 1: ", pelatis);
				}
				else {
					if (QU_enqueue(&tameio2,pelatis)) {
						printf("Customer %s was added to cash register 2: ", pelatis);
					}
					else
						printf("Cash Registers are Full. Customer %s leaves",pelatis);
				}
				break;
			case 2:
				if (!QU_empty(tameio1) && !QU_empty(tameio2)) {
					if (1+rand()%2==1) {
						QU_dequeue(&tameio1,&pelatis);
						printf("Customer %s was served from cash register 1", pelatis);
					}
					else {
						QU_dequeue(&tameio2,&pelatis);
						printf("Customer %s was served from cash register 2", pelatis);
					}
					free(pelatis);
				}
				else if (!QU_empty(tameio1)) {
					QU_dequeue(&tameio1,&pelatis);
					printf("Customer %s was served from cash register 1", pelatis);
					free(pelatis);
				}
				else if (!QU_empty(tameio2)) {
					QU_dequeue(&tameio2,&pelatis);
					printf("Customer %s was served from cash register2", pelatis);
					free(pelatis);
				}
				else {
					printf("The two cash registers are full!!");
				}
				break;
			case 3:
				printf("Exit");
				exit(0);
			default:
				printf("Wrong Input!");
		}
		printf("\n\n");
		system("pause");
	}
}



/* QU_init(): initializes queue */
void QU_init(QUEUE *q) {
	q->start =-1;
	q->finish=-1;
}

/* QU_empty(): returns TRUE/FALSE
 *          depending if queue is empty or not */
int QU_empty(QUEUE q) {
	return q.start==-1;
}

/* QU_full(): returns TRUE/FALSE
 *          depending if queue is full or not */
int QU_full(QUEUE q) {
	return q.start==(q.finish+1)%QUEUE_SIZE;
}

/* QU_enqueue(): Adds x on queue q
 *	returns TRUE: in case of success
 *		       FALSE: in case of failure */
int QU_enqueue(QUEUE *q,elem x) {
	if (QU_full(*q))
		return FALSE;
	else {
		if (QU_empty(*q)) {
			q->start=0;
			q->finish=0;
		}
		else {
			q->finish=(q->finish+1)%QUEUE_SIZE;
		}
		q->array[q->finish]=x;
		return TRUE;
	} 
}


/* QU_dequeue():  Removes the first item of the queue
 *	returns TRUE: in case of success
 *		       FALSE: in case of failure */
int QU_dequeue(QUEUE *q,elem *x) {
	if (QU_empty(*q)) {
		return FALSE;
	}
	else {
		*x=q->array[q->start];
		
		if (q->start == q->finish) /* queue empty */{
			q->start=-1;
			q->finish=-1;
		}
		else {
			q->start=(q->start+1)%QUEUE_SIZE;	
		}
		return TRUE;
	}
}
