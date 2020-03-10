#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int k;
    struct Node *left,*right;
    int lthread; // '1' if left pointer points to predecessor and also for inorder traversa
    // '1' if right pointer points to predecessor in Inorder Traversal
    int rthread;
}NODE;

NODE *insert(NODE *root,int ikey){
    // Create a new node
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    tmp->k = ikey;
    tmp->lthread = 1;
    tmp->rthread = 1;

    NODE *ptr = root;
    NODE *par = NULL; // Parent of key is to be inserted
    while(ptr != NULL){
        // If key already exists, return
        if(ikey == (ptr->k)){
            printf("Duplicate Key !\n");
            return root;
        }

        par = ptr; // Update parent pointer

        // Moving on left subtree.
        if(ikey < ptr->k)
        {
            if(ptr->lthread == 0){
                ptr = ptr->left;
            }
            else{
                break;
            }
        }
        else{
            if(ptr->rthread == 0){
                ptr = ptr->right;
            }
            else{
                break;
            }            
        }
    }

    if(par == NULL){
        root = tmp;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    else if(ikey < (par->k)){
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = 0;
        par->left = tmp;
    }
    else{
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = 0;
        par->right = tmp;
    }

    return root;
}

// Returns inorder successor using rthread
NODE *inorderSuccessor(NODE *ptr){
    // If rthread is set, we can quickly find
    if(ptr->rthread == 1){
        return ptr->right;
    }

    // Else return leftmost child of right subtree
    ptr = ptr->right;
    while(ptr->lthread == 0){
        ptr = ptr->left;
    }
    return ptr;
}

// Printing the threaded tree
void inorder(NODE *root){
    if(root == NULL){
        printf("Tree is empty");
    }
    // Reach leftmost node
    NODE *ptr = root;
    while(ptr->lthread == 0){
        ptr = ptr->left;
    }
    while (ptr != NULL){
        printf("%d ",ptr->k);
        ptr = inorderSuccessor(ptr);
    }
}

int main(void){
    NODE *root = NULL;

    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 
  
    inorder(root); 
    printf("\n");

    return 0;
}