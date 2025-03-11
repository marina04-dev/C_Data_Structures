#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 10      /* Megethos pinaka ouras */

typedef int elem;          /* typos dedomenwn ouras */

struct queue{
   elem array[QUEUE_SIZE]; /* pinakas stoixeiwn     */
   int start;			   /* arxi tis ouras 		*/
   int finish;             /* telos tis ouras       */
};

typedef struct queue QUEUE; /* Sinwnimo tis stoivas */


void QU_init(QUEUE *s);
int QU_empty(QUEUE s);
int QU_full(QUEUE s);
int QU_enqueue(QUEUE *s, elem x);
int QU_dequeue(QUEUE *s, elem *x);
void QU_print(QUEUE *q);

int main()
{
	int choice,elem,i;
	QUEUE q;
	
	QU_init(&q);
	
	while(1)
	{
		system("cls");
		printf("Menu Ouras: ");
		printf("\n--------------");
		printf("\n1-Eisagwgi");
		printf("\n2-Apomakrinsi");
		printf("\n3-Ektypwsi");
		printf("\n4-Eksodos");
		printf("\nEpilogi? ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nDwse Stoixeio: ");
				scanf("%d",&elem);
				if (QU_enqueue(&q,elem))
					printf("Egine i eisagwgi!");
				else
					printf("Den egine i eiasagwgi! Gemati Oura!");
				break;
			case 2:
				if (QU_dequeue(&q,&elem))
					printf("Egine i apomakrinsi tou %d", elem);
				else
					printf("Den egine i apomakrinsi! Adeia Oura!");
				break;
			case 3:
				QU_print(&q);
				break;
			case 4:
				printf("Bye Bye!!");
				exit(0);
			default:
				printf("Lathos eisodos!");
		}
		printf("\n\n");
		system("pause");
	}
}

/* QU_init(): arxikopoiei tin oura */
void QU_init(QUEUE *q)
{
	q->start =-1;
	q->finish=-1;
}

/* QU_empty(): epistrefei TRUE/FALSE
 *          analoga me to an i oura einai adeia */
int QU_empty(QUEUE q)
{
	return q.start==-1;
}

/* QU_full(): epistrefei TRUE/FALSE
 *          analoga me to an i oura einai gemati */
int QU_full(QUEUE q)
{
	return q.start==(q.finish+1)%QUEUE_SIZE;
}

/* QU_enqueue(): Eisagei to x stin oura q
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
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


/* QU_dequeue(): Kanei apomakrinsi tou prwtou stoixeiou tis ouras
 *	epistrefei TRUE: se periptwsi epitixias
 *		       FALSE: se periptwsi apotixias */
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
	
	/* 1. Ektypwsi twn stoixeiwn tis ouras */
	QU_init(&temp);
	
	while(!QU_empty(*q))
	{
		QU_dequeue(q,&x);
		printf("%3d|",x);
		QU_enqueue(&temp,x);
	}
	
	/* 2. Ksanagemisma tis ouras q */
	
	while (!QU_empty(temp))
	{
		QU_dequeue(&temp,&x);
		QU_enqueue(q,x);
	}
}
