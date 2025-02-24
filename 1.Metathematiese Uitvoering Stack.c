#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0 
#define SIZE 10 // stack's size

typedef double elem; // stack's items data type 

struct Stack {
    elem array[SIZE]; // array with items
    int top; // top of the stack
};

typedef struct Stack STACK; // Struct Stack's Alias 

void st_init(STACK *s); // initializes the stack's top to -1
int st_empty(STACK s); // returns true if stack is empty
int st_full(STACK s); // returns true if stack is full 
int st_push(STACK *s, elem x); // pushes an item to the top if stack is not full
int st_pop(STACK *s, elem *x); // pops an item of the top if stack is not empty

int main() {
    STACK st;
    double x;
    double y1;
    double y2;
    char c;
    printf("Enter the Metatematiese uitvoering: ");
    c=getchar();
    st_init(&st);
    while (c!='\n') {
        if (c>='0' && c<='9') { // digit scan
            x=c-'0'; 
            st_push(&st,x);
        }
        else { // operator scan 
            st_pop(&st, &y1);
            st_pop(&st, &y2);
            
            switch(c) {
                case '+':
                    x=y1+y2;
                    break;
                case '-':
                    x=y2-y1;
                    break;
                case '*':
                    x=y1*y2;
                    break;
                case '/':
                    x=y2/y1;
            }
            st_push(&st, x);
        }
        c=getchar();
    }
    
    // Print Of The Result
    st_pop(&st, &x);
    printf("\nThe result is: %.3f", x);
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
