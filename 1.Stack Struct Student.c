#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0 
#define SIZE 10 // stack's size

struct student {
    char name[80];
    int grade;
};

typedef struct student STUDENT;

typedef STUDENT elem; // stack's items data type 

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
    int choice, i;
    STUDENT elem;
    STACK st;
    
    st_init(&st);
    while(1) {
        system("cls");
        printf("Stack's Menu: ");
        printf("\n-------------");
        printf("\n1-Push");
        printf("\n2-Pop");
        printf("\n3-Print");
        printf("\n4-Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                fflush(stdin);
                printf("\nEnter the fullname: ");
                gets(elem.name);
                printf("\nEnter the grade: ");
                scanf("%d", &elem.grade);
                if (st_push(&st, elem)) {
                    printf("\nPush Completed Successfully!");
                }
                else {
                    printf("\nStack Is Full! Push Not Available!");
                }
                break;
            case 2:
                if (st_pop(&st, &elem)) {
                    printf("\nPop Completed Successfully!");
                    printf("\nPoped Element: %s (%d)", elem.name, elem.grade);
                }
                else {
                    printf("\nStack Is Empty! Pop Not Available!");
                }
                break;
            case 3:
                printf("\n\nStack has %d items: \n", st.top+1);
                for (i=0; i<=st.top; i++) {
                    printf("|%s (%d)", st.array[i].name, st.array[i].grade);
                }
                break;
            case 4:
                printf("\nExit Of The Program!");
                exit(0);
            default:
                printf("\nWrong Input!");
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
