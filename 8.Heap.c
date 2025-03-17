#include <stdlib.h>
#include <stdio.h>

#define TRUE 1 
#define FALSE 0
#define MAX_SIZE 31 
#define SIZE 100

typedef int elem;   // tree's data type 

struct heap_tree {
    elem data[MAX_SIZE];   // data
    int N;  // amount of elements
};

typedef struct heap_tree HEAP;  // heap's alias 


void HEAP_init(HEAP *heap); 
int HEAP_insert(HEAP *heap, elem x);
int HEAP_delete(HEAP *heap,elem *x);
void swap(elem *x, elem *y);

int main() {
    int choice,i,j;
	int data;
	int array[SIZE],N;
	HEAP heap,heapsort_heap;
	
	HEAP_init(&heap);
	
	while(1)
	{
		system("cls");
		printf("Menu Heap: ");
		printf("\n--------------");
		printf("\n1-Insertion");
		printf("\n2-Delete");
		printf("\n3-Print");
		printf("\n4-HeapSort");
		printf("\n5-Exit");		
		printf("\nEnter your choice? ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter Element: ");
				scanf("%d",&data);
				if (HEAP_insert(&heap,data))
					printf("Insertion completed succesfully!");
				else
					printf("Insertion cannot be done! Heap is full!");
				break;
			case 2:
				if (HEAP_delete(&heap,&data))
					printf("Element %d deleted succesfully", data);
				else
					printf("Delete cannot be done. Heap is empty!");
				break;
			case 3:
				for (i=0; i<heap.N; i++) {
					printf("%d ", heap.data[i]);
				}
				break;
			case 4:
				printf("Enter array's length: ");
				scanf("%d",&N);
				printf("Enter array's elements: ");
				for (i=0; i<N; i++) {
					printf("array[%d]=",i);
					//scanf("%d",&array[i]);
					array[i]=rand()%500;
				}
				
				HEAP_init(&heapsort_heap);
				for (i=0; i<N; i++)
					HEAP_insert(&heapsort_heap,array[i]);
				
				printf("\nSORTED: ");
				for (i=0; i<N; i++) {
					HEAP_delete(&heapsort_heap,&data);
					printf("%d ",data);
				}
				
				break;
			case 5:
				printf("Exit!!");
				exit(0);
			default:
				printf("Wrong Input!");
		}
		printf("\n\n");
		system("pause");
	}
    return 0;
}

void swap(elem *x, elem *y) {
    elem temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

// HEAP_init(): initializes the tree
void HEAP_init(HEAP *heap) {
    heap->N=0;
}

// HEAP_insert(): Inserts elem x in heap tree 
int HEAP_insert(HEAP *heap, elem x) {
    int posParent, posCurrent;
    
    // If heap does not have enough space
    if (heap->N == MAX_SIZE) {
        return FALSE;
    }
    
    // 1. New node's insertion 
    heap->data[heap->N]=x;
    heap->N++;
    
    // 2. Switch with the parent if it has smaller value
    posCurrent=heap->N -1;
    while (posCurrent>0) {
        posParent = (posCurrent-1)/2;
        // 2.1 It has bigger value from the parent 
        if (heap->data[posCurrent] > heap->data[posParent]) {
            swap(&heap->data[posCurrent], &heap->data[posParent]);
            posCurrent=posParent;
        }
        // 2.2 It took it's final position 
        else {
            break;
        }
        return TRUE;
    }
}


/* HEAP_delete(): Deletes the tree's root */
int HEAP_delete(HEAP *heap,elem *x) {
	int posCurrent, posLeft, posRight, pos;
	elem temp;

	/* If heap is empty */
	if (heap->N == 0)
		return FALSE;
		
	/* 1. Root's return  */
	*x=heap->data[0];
	
	/* 2. Putting the last element in root's place */
	heap->data[0]=heap->data[heap->N - 1];
	heap->N --;
	
	
	posCurrent=0;
	while(posCurrent<heap->N) {
		posLeft=2*posCurrent+1;
		posRight=2*posCurrent+2;
		
		if (posLeft >= heap->N)
			posLeft=-1;
		if (posRight >= heap->N)	
			posRight=-1;
			
		/* 1. It does not have children */
		if (posLeft==-1 && posRight==-1)
			break;
		/* 2. It has only left child */
		else if (posLeft!=-1 && posRight==-1) {
			if (heap->data[posCurrent] < heap->data[posLeft]) {
				swap(&heap->data[posCurrent],&heap->data[posLeft]);
				posCurrent=posLeft;
			}
			else 
				break;
		}
		/* 3. It has 2 children */
		else { // posLeft!=-1 && posRight!=-1 
			/*3.1 Search for the biggest of the 2 children */
			if (heap->data[posLeft] < heap->data[posRight])
				pos=posRight;
			else
				pos=posLeft;
				
			/*3.2 Switch if it is smaller */
			if (heap->data[posCurrent] < heap->data[pos]) {
				swap(&heap->data[posCurrent],&heap->data[pos]);
				posCurrent=pos;
			}
			else 
				break;
		}				
	}
}
