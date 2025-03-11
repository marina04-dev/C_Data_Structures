#include <stdio.h>
typedef int elem; // list's elements Data type

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

int main()
{
  
  
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
void LL_destroy(LIST PTR *head) {
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
        printf("%d ", current->data);
        current=current->next;
    }
}
