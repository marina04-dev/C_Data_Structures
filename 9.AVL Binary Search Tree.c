#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

#define DEPTH 100			/* Max Tree's Height Allowed */ 

typedef int elem;          	/* tree's data type */

struct node{			 	
   elem data; 		 		/* data */
   struct node *left;      	/* Left Child */
   struct node *right;     	/* Right Child */
   int height;				/* Tree's Height */
};

typedef struct node TREE_NODE; /* Tree's node alias */
typedef struct node *TREE_PTR; /* Tree's node pointer alias */

void TR_init(TREE_PTR *root);
int TR_empty(TREE_PTR root);
elem TR_data(TREE_PTR p);
int TR_insert_root(TREE_PTR *root,elem x);
int TR_insert_left(TREE_PTR node,elem x);
int TR_insert_right(TREE_PTR node,elem x);
int TR_delete_root(TREE_PTR *root, elem *x);
int TR_delete_left(TREE_PTR parent, elem *x);
int TR_delete_right(TREE_PTR parent, elem *x);
void TR_preorder(TREE_PTR v);
void TR_inorder(TREE_PTR v);
void TR_postorder(TREE_PTR v);

int TR_delete_BST(TREE_PTR *root, elem x);

TREE_PTR AVL_rotate_R(TREE_PTR C);
TREE_PTR AVL_rotate_L(TREE_PTR C);
TREE_PTR AVL_rotate_LR(TREE_PTR C);
TREE_PTR AVL_rotate_RL(TREE_PTR C);

TREE_PTR TR_insert_AVL(TREE_PTR *root, elem x);
int TR_delete_AVL(TREE_PTR *root, elem x);
int TR_search_AVL(TREE_PTR root, elem x);
void TR_print_AVL(TREE_PTR root);


int main() {
    TREE_PTR tree;
	
	TR_init(&tree);
	
	TR_insert_AVL(&tree, 2);
	TR_print_AVL(tree);
	printf("\n");
	TR_insert_AVL(&tree, 20);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 28);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 36);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 32);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 29);
	TR_print_AVL(tree);	
	printf("\n");
	TR_insert_AVL(&tree, 7);
	TR_print_AVL(tree);									
	printf("\n");
	TR_insert_AVL(&tree, 15);
	TR_print_AVL(tree);		
	printf("\n");
	TR_insert_AVL(&tree, 12);
	TR_print_AVL(tree);		
	printf("\n");
	TR_delete_AVL(&tree, 32);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 36);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 2);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 7);
	TR_print_AVL(tree);	
	printf("\n");
	TR_delete_AVL(&tree, 12);
	TR_print_AVL(tree);
	printf("\n");
	TR_delete_AVL(&tree, 15);
	TR_print_AVL(tree);		
	printf("\n");
	TR_delete_AVL(&tree, 28);
	TR_print_AVL(tree);
	printf("\n");
	TR_delete_AVL(&tree, 29);
	TR_print_AVL(tree);
	printf("\n");
	TR_delete_AVL(&tree, 20);
	TR_print_AVL(tree);	
			
	return 0;
}


/* TR_init(): initializes the tree */
void TR_init(TREE_PTR *root) {
   *root=NULL;
}

/* TR_empty(): returns TRUE/FALSE
 *          depending if tree is empty */
int TR_empty(TREE_PTR root) {
   return root == NULL;
}


/* TR_data(): returns node's data 
	      that is shown by pointer p */
elem TR_data(TREE_PTR p) {
   return p->data;
}


/* TR_insert_root(): Inserts element x
			in tree's root */
int TR_insert_root(TREE_PTR *root,elem x) {
	TREE_PTR newnode;
	
	if (*root!=NULL)
		return FALSE;
	
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode) {
		printf("Error Allocating Memory");
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;

	*root=newnode;
	return TRUE;
}

/* TR_insert_left(): Inserts element x
			as node's left child */
int TR_insert_left(TREE_PTR node,elem x) {
	TREE_PTR newnode;
	
	if (node->left!=NULL)
		return FALSE;
	
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
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

/* TR_insert_right(): Inserts element x
			as node's right child */
int TR_insert_right(TREE_PTR node,elem x) {
	TREE_PTR newnode;
	
	if (node->right!=NULL)
		return FALSE;
	
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
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

/* TR_delete_root(): Deletes the tree's root 
 if only it has no children */
int TR_delete_root(TREE_PTR *root, elem *x) {
	if ((*root)->left!=NULL || (*root)->right!=NULL)
		return FALSE;	

	*x=(*root)->data;
	free(*root);
	*root=NULL;
	return TRUE;
}

/* TR_delete_left(): Deletes the node's parent left child
	 (if it has no children) */
int TR_delete_left(TREE_PTR parent, elem *x) {
	TREE_PTR current;
	
	if (parent->left==NULL)
		return FALSE;
	
	current=parent->left;
	if (current->left!=NULL || current->right!=NULL)
		return FALSE;	

	*x=current->data;
	free(current);
	parent->left=NULL;
	return TRUE;
}

/* TR_delete_right(): Deletes the node's parent right child
	 (if it has no children */
int TR_delete_right(TREE_PTR parent, elem *x) {
	TREE_PTR current;
	
	if (parent->right==NULL)
		return FALSE;
	
	current=parent->right;
	if (current->left!=NULL || current->right!=NULL)
		return FALSE;	

	*x=current->data;
	free(current);
	parent->right=NULL;
	return TRUE;
}

void TR_print_node(TREE_PTR v) {
	printf("%d ",v->data);
}

/* TR_preorder(): Print preorder path	 */
void TR_preorder(TREE_PTR v) {
	if(v!=NULL) {
		TR_print_node(v);
		TR_preorder(v->left);
		TR_preorder(v->right);
	}
}

/* TR_inorder(): Print inorder path	 */
void TR_inorder(TREE_PTR v) {
	if(v!=NULL) {
		TR_inorder(v->left);
		TR_print_node(v);
		TR_inorder(v->right);
	}
}

/* TR_postorder(): Print postorder path */
void TR_postorder(TREE_PTR v) {
	if(v!=NULL) {
		TR_postorder(v->left);
		TR_postorder(v->right);
		TR_print_node(v);
	}
}

/* TR_insert_BST(): insert x in Binary Search Tree 
	with root 'root'	 */
int max(int x, int y) {
	if (x>y)
		return x; 
	else 
		return y;
}

int height(TREE_PTR R) {
	if (R==NULL)
		return 0;
	else
		return R->height; 
}

TREE_PTR AVL_rotate_R(TREE_PTR C) {
	TREE_PTR L = C->left; 
	C->left = L->right; 
	L->right = C; 
	C->height = max(height(C->left), height(C->right))+1;
	L->height = max(height(L->left), height(L->right))+1;
	return L; 
}

TREE_PTR AVL_rotate_L(TREE_PTR C) {
   TREE_PTR R = C->right; 
   C->right = R->left; 
   R->left = C; 
   C->height = max(height(C->left), height(C->right))+1;
   R->height = max(height(R->left), height(R->right))+1;
   return R; 
}

TREE_PTR AVL_rotate_LR(TREE_PTR C) {
   C->left = AVL_rotate_L(C->left);
 
   return AVL_rotate_R(C); 
}

TREE_PTR AVL_rotate_RL(TREE_PTR C) {
   C->right = AVL_rotate_R(C->right);
 
   return AVL_rotate_L(C); 
}
	
TREE_PTR TR_insert_AVL(TREE_PTR *root, elem x) {
	if (*root==NULL) {
		TR_insert_root(root, x);
		(*root)->height=1; 
		return *root; 
	}
	else if (x < (*root)->data) {
		(*root)->left=TR_insert_AVL(&((*root)->left), x);
		if (height((*root)->left)-height((*root)->right)==2) {
			if(x < (*root)->left->data)
				(*root)=AVL_rotate_R(*root);
			else
				(*root)=AVL_rotate_LR(*root);
		}
	}
	else if (x > (*root)->data) {
		(*root)->right=TR_insert_AVL(&((*root)->right), x);
		if (height((*root)->left)-height((*root)->right)==-2) {
			if(x > (*root)->right->data)
				(*root)=AVL_rotate_L(*root);
			else
				(*root)=AVL_rotate_RL(*root);
		}
	}
	// else x == root->x : we do nothing
	
	(*root)->height = max(height((*root)->left), height((*root)->right))+1;
	return (*root); 
}

int TR_delete_AVL(TREE_PTR *root, elem x) {
	TREE_PTR pred[DEPTH], new_root;
	int orient[DEPTH]; //0-left, 1-right
	TREE_PTR current; 
	int i=0,j;
	
	
	if (*root==NULL) // empty tree
		return FALSE; 
	
	/* Find all ancestors */
	/* From root until the node */	
	current=*root;
	while(current!=NULL) {
		if (x == current->data)
			break;
		else if (x < current->data) {
			orient[i]=0;
			pred[i++]=current;
			current=current->left;	
		}
		else { // x > current->data 
			orient[i]=1;
			pred[i++]=current;
			current=current->right;
		}					
	}
	
	if (current==NULL) // was not found
		return FALSE; 
	
	if (current->left!=NULL && current->right!=NULL) {
		orient[i]=1;
		pred[i++]=current;
		current=current->right;
		
		while (current->left!=NULL) {
			orient[i]=0;
			pred[i++]=current;
			current=current->left;
		}		
	}
	
	TR_delete_BST(root, x);
	
	for (j=i-1; j>=0; j--) {
		if (height(pred[j]->left)-height(pred[j]->right)==2) {
			if(height(pred[j]->left->left)>height(pred[j]->left->right))
				new_root=AVL_rotate_R(pred[j]);
			else
				new_root=AVL_rotate_LR(pred[j]);				
		}
		else if (height(pred[j]->left)-height(pred[j]->right)==-2) {
			if(height(pred[j]->right->right)>height(pred[j]->right->left))
				new_root=AVL_rotate_L(pred[j]);
			else
				new_root=AVL_rotate_RL(pred[j]);
		}
		else
			continue; 
			
		if (j==0)
			*root = new_root;
		else
			if (orient[i-1]==0)
				pred[i-1]->left=new_root;
			else
				pred[i-1]->right=new_root; 
	}
}

/* TR_delete_BST(): Deletes element x from Binary Search
    Tree with root 'root' */
int TR_delete_BST(TREE_PTR *root, elem x) {
	TREE_PTR current, parent, nextOrdered;
	int p; /* 1. right child, 2. current's left child */
	int temp;
	
	/* 1. Node's Search */
	parent=NULL;
	current=*root;
	while (current!=NULL) {
		if (x == current->data)
			break;
		else if (x < current->data) {
			parent=current;
			p=1;
			current=current->left;	
		}
		else { // x > current->data 
			parent=current;
			p=2;
			current=current->right;
		}			
	}
	if (current==NULL)
		return FALSE;
	
	/* 2.1 If it hasn't children */
	if (current->left==NULL && current->right==NULL) {
		free(current);
		
		if (parent==NULL)
			*root=NULL;
		else
			if (p==1)
				parent->left=NULL;
			else
				parent->right=NULL;
		return TRUE;
	}
	/* 2.2 It has only left child */
	else if (current->left!=NULL && current->right==NULL) {
		if (parent==NULL)
			*root=current->left;
		else
			if (p==1)
				parent->left=current->left;
			else
				parent->right=current->left;
		free(current);
		return TRUE;
	}
	/* 2.3 It has only right child */
	else if (current->left==NULL && current->right!=NULL) {
		if (parent==NULL)
			*root=current->right;
		else
			if (p==1)
				parent->left=current->right;
			else
				parent->right=current->right;
		free(current);
		return TRUE;
	}
	/* 2.4 It has left and right children */
	else {
		/* 2.4.1 Finds the next in inorder's state */
		p=1;
		nextOrdered=current->right;
		
		while (nextOrdered->left!=NULL) {
			parent=nextOrdered;
			nextOrdered=nextOrdered->left;
			p=2;
		}
		
		/*2.4.2 Switch values with the node to be deleted */
		current->data=nextOrdered->data;
		
		/*2.4.3 Deletes the node */
		if (p==1) /*2.4.3.1 Next is the right child */ {
			current->right=nextOrdered->right;
			free(nextOrdered);	
		}
		else  {
			parent->left=nextOrdered->right;
			free(nextOrdered);
		}
	}
}

void TR_print_AVL(TREE_PTR root) {
	if (root->left!=NULL) {
		printf("(");
		TR_print_AVL(root->left);
		printf(")");	
	}
	printf(" %d ", root->data);
	if (root->right!=NULL) {
		printf("(");
		TR_print_AVL(root->right);
		printf(")");		
	}
}

/* TR_search_AVL(): Search for x in Binary Search Tree
    with root 'root'	 */
int TR_search_AVL(TREE_PTR root, elem x) {
	TREE_PTR current;
	
	current=root;
	
	while (current!=NULL) {
		if (x == current->data)
			return TRUE;
		else if (x < current->data)
			current=current->left;
		else // x > current->data 
			current=current->right;
	}
	return FALSE;
}
