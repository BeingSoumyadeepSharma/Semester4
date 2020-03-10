#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
typedef struct Node{
    int key;
    struct Node *left, *right;
    int height;
}NODE;

int height(NODE *); // Function to get the height of the tree
int max(int,int); // Function to get the maximum between the two numbers
NODE *rightRotate(NODE *); // For Right Rotation
NODE *leftRotate(NODE *); // For Left Rotation
int getBalance(NODE *); // Get Balance Factor of Node
NODE *insert(NODE *,int); // Inserting the node in the AVL Tree
void inorder(NODE *); // To print the inorder of the AVL Tree
void preOrder(NODE *); // To print the preorder of the AVL Tree

int main(void){
    NODE *root = NULL;

    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 

    inorder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    return 0;
}

int height(NODE *N){
    if(N == NULL){
        return 0;
    }
    return (N->height);
}

int max(int a,int b){
    return (a > b)? a : b;
}

NODE *rightRotate(NODE *y){
    NODE *x = y->left;
    NODE *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heigths 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

NODE *leftRotate(NODE *x){
    NODE *y = x->right;
    NODE *T2 = y->left;

    // Performs Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;  
}

int getBalance(NODE *N){
    if(N == NULL){
        return 0;
    }
    return height(N->left) - height(N->right);
}

NODE *insert(NODE *root, int key){
    int balance;
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    tmp->key = key;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;

    if(root == NULL){
        root = tmp;
        return(root);
    }

    if(key < root->key){
        root->left = insert(root->left,key);
    }
    else if(key > root->key){
        root->right = insert(root->right,key);
    }
    else{
        return root;
    }

    root->height = 1 + max(height(root->left),height(root->right));
    balance = getBalance(root);
    // R-R Rotation
    if(balance < -1 && key > root->right->key){
        return leftRotate(root);
    }
    // L-L Rotation
    if(balance > 1 && key < root->left->key){
        return rightRotate(root);
    }
    //Left - Right Case
    if(balance > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right-Left Case
    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(NODE *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d  ",root->key);
        inorder(root->right);
    }
}

void preOrder(NODE *root){
    if(root != NULL){
        printf("%d  ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}