#include <stdio.h>
#include <stdlib.h>

#define N 8 
#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 10 /* arrays size */

typedef int data_type;

struct data_array {
    data_type data;
    int priority;
};

typedef struct data_array elem;          /* queue's data type  */

struct queue {
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
	elem x;
	QUEUE q;
	
	
	QU_init(&q);
	
	while(1) {
		system("cls");
		printf("Queue Menu: ");
		printf("\n--------------");
		printf("\n1-Enter Element");
		printf("\n2-Remove Element");
		printf("\n3-Queue Print");
		printf("\n4-Exit");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
			    printf("Enter the data: ");
			    scanf("%d", &x.data);
			    printf("Enter the priority: ");
			    scanf("%d", &x.priority);
			    if (QU_enqueue(&q,x)) {
				    printf("Element successfully added");
				}
				else {
				    printf("Addition Cannot Be Done! Full Queue!");
				}
				break;
			case 2:
				if (QU_dequeue(&q,&x)) {
				    printf("Element successfully removed");
				}
				else {
				    printf("Removal Cannot Be Done! Empty Queue!");
				}
				break;
			case 3:
				if (q.start != -1) {
				    i=q.start;
				    while (1) {
				        printf("|%3d(%d)", q.array[i].data, q.array[i].priority);
				        if (i==q.finish) {
				            break;
				        }
				        i=(i+1)%QUEUE_SIZE;
				    }
				}
				break;
			case 4:
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
    int i;
    elem temp;
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
		i=q->finish;
		while (i!=q->start) {
		    if (i>0) {
		        if (q->array[i-1].priority < q->array[i].priority) {
		            temp=q->array[i-1];
		            q->array[i-1]=q->array[i];
		            q->array[i]=temp;
		            i--;
		        }
		        else {
		            break;
		        }
		    }
		    else {
		        if (q->array[QUEUE_SIZE-1].priority < q->array[i].priority) {
		            temp=q->array[QUEUE_SIZE-1];
		            q->array[QUEUE_SIZE-1]=q->array[i];
		            q->array[i]=temp;
		            i=QUEUE_SIZE-1;
		        }
		        else {
		            break;
		        }
		    }
		}
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
