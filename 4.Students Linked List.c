#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1;
#define FALSE 0;

struct student {
    char name[80];
    int degree;
};

typedef struct student elem; // list's elements Data type

struct node { 
    elem data;
    struct node *next;
};

// aliases 
typedef struct node LIST_NODE;
typedef struct node *LIST_PTR;


void LL_init(LIST_PTR *head);
int LL_empty(LIST_PTR head);
elem LL_data(LIST_PTR p);
int LL_insert_start(LIST_PTR *head, elem x);
int LL_insert_after(LIST_PTR p, elem x);
int LL_delete_start(LIST_PTR *head, elem *x);
int LL_delete_after(LIST_PTR prev, elem *x);
void LL_print(LIST_PTR head);
void LL_destroy(LIST_PTR *head);

int LL_insert(LIST_PTR *head, elem x);
int LL_delete(LIST_PTR *head, char *s);
double LL_average(LIST_PTR head);
int LL_pass(LIST_PTR head);


int main() {
    int choice;
    LIST_PTR list;
    elem stud;
    
    LL_init(&list);
    while (1) {
        printf("Menu\n");
        printf("=====\n");
        printf("1-Student Enter\n");
        printf("2-Delete Student\n");
        printf("3-Print Students\n");
        printf("4-Average Grade\n");
        printf("5-Pass Students\n");
        printf("6-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter student's name: ");
                fgets(stud.name, 80, stdin);
                printf("\nEnter student's grade: ");
                scanf("%d", &stud.degree);
                if (LL_insert(&list, stud)) {
                    printf("Inserted With Success!\n\n");
                }
                else {
                    printf("Student Not Found!\n\n");
                }
                break;
            case 2:
                printf("Enter student's name: ");
                fgets(stud.name, 80, stdin);
                if (LL_delete(&list, stud.name)) {
                    printf("Deleted With Success!\n\n");
                }
                else {
                    printf("Student Not Found!\n\n");
                }
                break;
            case 3:
                LL_print(list);
                printf("\n\n");
                break;
            case 4:
                printf("Average Grade is: %.2lf\n\n", LL_average(list));
                break;
            case 5:
                printf("Total Students Who Passed: %d\n\n", LL_pass(list));
                break;
            case 6:
                printf("Exit");
                LL_destroy(&list);
                exit(0);
            default:
                printf("Wrong Input!");
        }
    }
    
  
}

// LL_init(): initializes the list
void LL_init(LIST_PTR *head) {
    *head = NULL;
}

// LL_empty(): returns TRUE if list is empty and false either
int LL_empty(LIST_PTR head) {
    return head == NULL;
}

// LL_data(): returns the node's data of pointer p 
elem LL_data(LIST_PTR p) {
    return p->data;
}

// LL_insert_start(): Enters element x at the start of our linked list 
int LL_insert_start(LIST_PTR *head, elem x) {
    LIST_PTR newnode;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
    return TRUE;
}

// LL_insert_after(): Enters element x after element p 
int LL_insert_after(LIST_PTR p, elem x) {
    LIST_PTR newnode;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->next=p->next;
    p->next=newnode;
    return TRUE;
}

// LL_delete_start(): Deletes element x at the start of our linked list 
int LL_delete_start(LIST_PTR *head, elem *x) {
    LIST_PTR current;
    if (*head==NULL) {
        return FALSE;
    }
    current=*head;
    *x=current->data;
    (*head)=(*head)->next;
    free(current);
    return TRUE;
}

// LL_delete_after(): Deletes element x after element p 
int LL_delete_after(LIST_PTR prev, elem *x) {
    LIST_PTR current;
    if (prev->next==NULL) {
        return FALSE;
    }
    current=prev->next;
    *x=current->data;
    prev->next=current->next;
    free(current);
    return TRUE;
}

// LL_destroy(): Memory Release
void LL_destroy(LIST_PTR *head) {
    LIST_PTR ptr;
    while (*head!=NULL) {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}

// LL_print(): Prints a linked list's elements 
void LL_print(LIST_PTR head) {
    LIST_PTR current;
    current=head;
    while (current!=NULL) {
        printf("(%s, %d) ", current->data.name, current->data.degree);
        current=current->next;
    }
}

int LL_insert(LIST_PTR *head, elem x) {
	LIST_PTR current, prev; 
	
	if (*head==NULL)
		return LL_insert_start(head, x);
	else {
		current=*head;
		prev=current;
		
		while(current!=NULL) {
			if (strcmp(current->data.name, x.name)>0) {
				if (current==*head)
					return LL_insert_start(head, x);
				else 
					return LL_insert_after(prev, x);
			}
			
			prev=current; 
			current=current->next;
		}
		
		return LL_insert_after(prev, x);
	}	
}

int LL_delete(LIST_PTR *head, char *s) {
	LIST_PTR current, prev; 
	elem temp; 

	if (*head==NULL)
		return FALSE; 
	
	current = *head; 
	prev=current; 
	while(current!=NULL) {
		
		if (strcmp(current->data.name,s)==0) {
			if (current==*head)
				return LL_delete_start(head, &temp);
			else 
				return LL_delete_after(prev, &temp);
		}
		
		prev = current; 
		current=current->next;
	}
	
	return FALSE;
}

double LL_average(LIST_PTR head) {
	LIST_PTR current; 
	int sum, cnt; 
	
	current=head;
	sum=0; 
	cnt=0; 
	while (current!=NULL) {
		sum += current->data.degree; 
		cnt += 1; 
		current=current->next; 
	}
	
	return sum/(double)cnt; 
}

int LL_pass(LIST_PTR head) {
	LIST_PTR current;
	int cnt; 
	
	current=head;
	cnt=0; 
	while (current!=NULL) {
		if (current->data.degree>=5)
			cnt++; 
		current=current->next;
	}
	
	return cnt; 
}
