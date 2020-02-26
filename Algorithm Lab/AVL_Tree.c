#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    int bf,height;
    struct Tree *left, *right;
}NODE;

NODE *root = NULL;

void insertNode(int);
int heightTree(NODE *);
void inorder(NODE *);
void postorderAVL(NODE *);
NODE *leftRotate(NODE *);
NODE *rightRotate(NODE *);

int main(void){
    return 0;
}

void insertNode(int k){
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    tmp->key = k;
    tmp->left = tmp->right = NULL;

    if(!root){
        root = tmp;
        return;
    }

    NODE *x = root;
    NODE *y = NULL;
    while(x){
        y = x;
        if(k < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }       
    }
    if(k < y->key){
        y->left = tmp;
    }
    else if(k > y->key){
        y->right = tmp;
    }
}

int heightTree(NODE *h){
    int lheight, rheight;
    if(h == NULL){
        return 0;
    }
    else{
        lheight = heightTree(h->left);
        rheight = heightTree(h->right);

        if(lheight > rheight){
            return(lheight + 1);
        }
        else{
            return(rheight + 1);
        }
    }
}

void inorder(NODE *h){
    if(h != NULL){
        inorder(h->left);
        printf("%d  ",h->key);
        inorder(h->right);
    }
}

void postorder(NODE *h){
    if(h != NULL){
        postorder(h->left);
        postorder(h->right);
        h->bf = heightTree(h->left) - heightTree(h->right);
        if(h->bf == 2){

        }
    }
}

NODE *rightRotate(NODE *y){
    NODE *x = y->left;
    NODE *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->right),height(x->left))+1;
    return x;
}

NODE *leftRotate(NODE *x){
    NODE *y = x->right;
    NODE *T2 = y->left;
    y->left = x;
    y->right = T2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->right),height(y->left))+1;
    return x;
}
