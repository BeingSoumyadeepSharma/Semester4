#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	int bf;
	struct Node *left, *right;
}NODE;

NODE *insert(NODE *,int);
int height_Tree(NODE *);
void preOrder(NODE *);
void inOrder(NODE *);
NODE *postOrder(NODE *);
NODE *rr_rotation(NODE *,NODE *,NODE *);
NODE *ll_rotation(NODE *,NODE *,NODE *);
NODE *lr_rotation(NODE *,NODE *,NODE *);
NODE *rl_rotation(NODE *,NODE *,NODE *);

int main(void){
	NODE *root = NULL;
	return 0;
}

int height_Tree(NODE *root){
	int leftheight, rightheight;
	if(root == NULL)
		return 0;
	else{
		leftheight = height_Tree(root->left);
		rightheight = height_Tree(root->right);
		
		if(leftheight > rightheight){
			return(leftheight + 1);
		}
		else{
			return(rightheight + 1);
		}
	}
}

NODE *insert(NODE *root,int k){
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->key = k;
	temp->left = temp->right = NULL;
	
	NODE *x = root;
	NODE *y = NULL;
	while(x != NULL){
		y = x;
		if(k < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	if(y == NULL){
		y = temp;
	}
	else if(k < y->key){
		y->left = temp;
	}
	else{
		y->right = temp;
	}
	root = postOrder(root);
	return y;
}

NODE *postOrder(NODE *root){
	NODE *final = root;
	if(root == NULL){
		return root;
	}
	root = postOrder(root->left);
	root = postOrder(root->right);
	root->bf = height_Tree(root->left) - height_Tree(root->right);
	if(root->bf == 2){
		if(root->left->bf == 1){
			final = rr_rotation(final,root->left,root);
		else if(root->left->bf == -1)
			final = lr_rotation(final,root->right,root);
	}
	if(root->bf == -2){
		if(root->right->bf == -1)
			final = ll_rotation(final,root->right,root);
		else if(root->left->bf == 1){
			final = rl_rotation(final,root->left,root);
	return final;
}

NODE *rr_rotation(NODE *root,NODE *n,NODE *p){
	NODE *t;
	if(p == NULL){
		root = n->left;
	else if(p->left == n)
		p->left = n->left;
	else
		p->right = n->left;
	t = n->left;
	n->left = (n->left)->right;
	t->right = n;
	return t;
}

NODE *ll_rotation(NODE *root,NODE *n,NODE *p){
	NODE *t;
	if(p == NULL){
		root = n->right;
	else if(p->right == n)
		p->right = n->right;
	else
		p->left = n->right;
	t = n->right;
	n->right = (n->right)->left;
	t->left = n;
	return t;
}

NODE *ll_rotation(NODE *n,NODE *p){
}