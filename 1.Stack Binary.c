#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0 
#define SIZE 10 // stack's size

typedef int elem; // stack's items data type 

struct Stack {
    elem array[SIZE]; // array with items
    int top; // top of the stack
};

typedef struct Stack STACK; // Struct Stack's Alias 

void st_init(STACK *s); // initializes the stack's top to -1
int st_empty(STACK s); // returns true if stack ie empt
int st_full(STACK s); // returns true if stack is full 
int st_push(STACK *s, elem x); // pushes an item to the top if stack is not full
int st_pop(STACK *s, elem *x); // pops an item of the top if stack is not empty

int main() {
    STACK st;
    int x;
    
    // Scan of the integer number 
    do {
        printf("Enter a positive integer: ");
        scanf("%d", &x);
    } while (!(x>0));
    
    // Conversion to binary 
    st_init(&st);
    
    while (x>=1) {
        st_push(&st, x%2);
        x=x/2;
    }
    
    // Printing of the number 
    printf("\nThe Binary Number Is: ");
    while (!st_empty(st)) {
        st_pop(&st, &x);
        printf("%d", x);
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

int st_push(STACK *s,elem x) {
	if (st_full(*s)) {
		return FALSE;
	}
	else {
		s->top++;
		s->array[s->top]=x;
		return TRUE;
	}
}

int st_pop(STACK *s,elem *x) {
	if (st_empty(*s)) {
		return FALSE;
	}
	else {
		*x=s->array[s->top];
		s->top--;
		return TRUE;
	}
}
