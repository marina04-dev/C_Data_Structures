#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0 

typedef int elem; // tree's data type 

struct node {
    elem data;   // data
    struct node *left;  // left child 
    struct node *right;  // right child 
};

typedef struct node TREE_NODE;  // tree's node alias 
typedef struct node *TREE_PTR;  // tree's node pointer alias 


void TR_init(TREE_PTR *root);
int TR_empty(TREE_PTR root);
elem TR_data(TREE_PTR p);
int TR_insert_root(TREE_PTR *root, elem x);
int TR_insert_left(TREE_PTR node, elem x);
int TR_insert_right(TREE_PTR node, elem x);
int TR_delete_root(TREE_PTR *root, elem *x);
int TR_delete_left(TREE_PTR parent, elem *x);
int TR_delete_right(TREE_PTR parent, elem *x);
void TR_print_node(TREE_PTR v);
void TR_preorder(TREE_PTR v);
void TR_inorder(TREE_PTR v);
void TR_postorder(TREE_PTR v);

int main() {
    
}

//TR_init(): initializes the tree's root 
void TR_init(TREE_PTR *root) {
    *root = NULL;
}


// TR_empty(): returns TRUE if tree is empty else FALSE 
int TR_empty(TREE_PTR root) {
    return root == NULL;
}


// TR_data(): returns the content of a tree's node 
elem TR_data(TREE_PTR p) {
    return p->data;
}


// TR_insert_root(): inserts elem x in the tree's root 
int TR_insert_root(TREE_PTR *root, elem x) {
    TREE_PTR newnode;
    if (*root!=NULL) {
        return FALSE;
    }
    
    newnode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    
    *root=newnode;
    return TRUE;
}


// TR_insert_left(): inserts elem x as left child of node  
int TR_insert_left(TREE_PTR node, elem x) {
    TREE_PTR newnode;
    if (node->left!=NULL) {
        return FALSE;
    }
    
    newnode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    
    node->left=newnode;
    return TRUE;
}


// TR_insert_right(): inserts elem x as right child of node  
int TR_insert_right(TREE_PTR node, elem x) {
    TREE_PTR newnode;
    if (node->right!=NULL) {
        return FALSE;
    }
    
    newnode = (TREE_NODE *)malloc(sizeof(TREE_NODE));
    if (!newnode) {
        printf("Error Allocating Memory!");
        return FALSE;
    }
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    
    node->right=newnode;
    return TRUE;
}


// TR_delete_root(): deletes a tree's root if only it has no children 
int TR_delete_root(TREE_PTR *root, elem *x) {
    if ((*root)->left!=NULL || (*root)->right!=NULL) {
        return FALSE;
    }
    
    *x=(*root)->data;
    free(*root);
    *root=NULL;
    return TRUE;
}

// TR_delete_left(): deletes the left child of node parent (if only it has no children)
int TR_delete_left(TREE_PTR parent, elem *x) {
    TREE_PTR current;
    if (parent->left==NULL) {
        return FALSE;
    }
    current=parent->left;
    if (current->left!=NULL || current->right!=NULL) {
        return FALSE;
    }
    *x=current->data;
    free(current);
    parent->left=NULL;
    return TRUE;
}


// TR_delete_right(): deletes the right child of node parent (if only it has no children)
int TR_delete_right(TREE_PTR parent, elem *x) {
    TREE_PTR current;
    if (parent->right==NULL) {
        return FALSE;
    }
    current=parent->right;
    if (current->left!=NULL || current->right!=NULL) {
        return FALSE;
    }
    *x=current->data;
    free(current);
    parent->right=NULL;
    return TRUE;
}

// TR_print_node(): prints node's data 
void TR_print_node(TREE_PTR v) {
    printf("%d ", v->data);
}


// TR_preorder(): prints as preorder order 
void TR_preorder(TREE_PTR v) {
    if (v!=NULL) {
        TR_print_node(v);
        TR_preorder(v->left);
        TR_preorder(v->right);
    }
}


// TR_inorder(): prints as inorder order 
void TR_inorder(TREE_PTR v) {
    if (v!=NULL) {
        TR_inorder(v->left);
        TR_print_node(v);
        TR_inorder(v->right);
    }
}


// TR_postorder(): prints as postorder order 
void TR_postorder(TREE_PTR v) {
    if (v!=NULL) {
        TR_postorder(v->left);
        TR_postorder(v->right);
        TR_print_node(v);
    }
}
