#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int elem;

struct node {
    elem data;
    struct node *next;
};

typedef struct node LIST_NODE;
typedef struct node *LIST_PTR;

void CL_init(LIST_PTR *head);
int CL_empty(LIST_PTR head);
elem CL_data(LIST_PTR p);
int CL_insert_start(LIST_PTR *head, elem x);
int CL_insert_after(LIST_PTR p, elem x);
int CL_delete_start(LIST_PTR *head, elem *x);
int CL_delete_after(LIST_PTR prev, elem *x);
void CL_print(LIST_PTR head);
void CL_destroy(LIST_PTR *head);

int main() {
        LIST_PTR list; 
	elem temp; 
	
	CL_init(&list);
	
	CL_insert_start(&list, 1);
	CL_print(list);
	printf("\n");
	
	CL_insert_start(&list, 2);
	CL_print(list);
	printf("\n");
	
	CL_insert_after(list->next, 3);
	CL_print(list);
	printf("\n");

	CL_insert_after(list, 4);
	CL_print(list);
	printf("\n");
	
	CL_delete_start(&list, &temp);
	CL_print(list);
	printf("\n");

	CL_delete_after(list->next, &temp);
	CL_print(list);
	printf("\n");

	CL_delete_start(&list, &temp);
	CL_print(list);
	printf("\n");

	CL_delete_start(&list, &temp);
	CL_print(list);
	printf("\n");
	
	CL_destroy(&list);
}


// CL_init(): initializes the circle linked list
void CL_init(LIST_PTR *head) {
    *head = NULL;
}

// CL_empty(): returns TRUE if circle linked list is empty else returns FALSE
int CL_empty(LIST_PTR head) {
    return head == NULL;
}

// CL_data(): returns the data of node p
elem CL_data(LIST_PTR p) {
    return p->data;
}

// CL_insert_start(): Enters element x at the start of our linked list 
int CL_insert_start(LIST_PTR *head, elem x) {
    LIST_PTR newnode, last;
    newnode = (LIST_NODE *)malloc(sizeof(LIST_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    if (*head == NULL) {
        newnode->next=newnode;
        *head=newnode;
    }
    else {
        last=*head;
        while (last->next!=*head) {
            last=last->next;
        }
        last->next=newnode;
        newnode->next=*head;
        *head=newnode;
    }
    return TRUE;
}

// CL_insert_after(): Enters element x after element p 
int CL_insert_after(LIST_PTR p, elem x) {
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

// CL_delete_start(): Deletes element x at the start of our linked list 
int CL_delete_start(LIST_PTR *head, elem *x) {
    LIST_PTR next, last;
    // 0 elements
    if (*head==NULL) {
        return FALSE;
    }
    
    // 1 element
    if (*head==(*head)->next) {
        *x=(*head)->data;
        free(*head);
        *head=NULL;
        return TRUE;
    }
    
    // >= 2 elements
    last = (*head)->next;
    while (last->next!=(*head)) {
        last=last->next;
    }
    last->next=(*head)->next;
    
    *x=(*head)->data;
    free(*head);
    (*head)=last->next;
    return TRUE;
}

// CL_delete_after(): Deletes element x after element p 
int CL_delete_after(LIST_PTR prev, elem *x) {
    LIST_PTR current;
    while (prev->next!=current)
		prev=prev->next;
		
	*x=current->data;
	
	prev->next=current->next;
	free(current);
	return TRUE;
}

// CL_destroy(): Memory Release
void CL_destroy(LIST_PTR *head) {
    LIST_PTR ptr;
    elem temp;
	
	while (*head!=NULL)
		CL_delete_start(head, &temp);
}

// CL_print(): Prints a linked list's elements 
void CL_print(LIST_PTR head) {
    LIST_PTR current;
    if (head!=NULL) {
		printf("%d ", head->data);
		
		current=head->next;
		while(current!=head) {
			printf("%d ",current->data);
			current=current->next;
		}
	}
}
