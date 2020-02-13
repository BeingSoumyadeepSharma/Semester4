#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *left, *right;
}NODE;

NODE *root = NULL;

void insertNode(int);
int heightTree(NODE *);
void inorder(NODE *);
void deleteNode(int);
NODE *searchParent(int);
NODE *searchNode(int); 

int main(void){
    int ch, inp;
    while(1){
        printf("\033[1;34m");
        printf("Enter your choice:\n\t1. Insert\n\t2. Height\n\t3. Inorder\n\t4. Delete\n\t5. Search\n\t6. Exit\n");
        printf("\033[0m");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
            {
                printf("Enter the number to be inserted: ");
                scanf("%d",&inp);
                printf("\n");
                insertNode(inp);
            }
            break;
            case 2:
            {
                printf("The height of the BST is: %d\n",heightTree(root)-1);
            }
            break;
            case 3:
            {
                printf("Inorder traversal:  ");
                inorder(root);
                printf("\n");
            }
            break;
            case 4:
            {
                printf("Enter the number to be deleted: ");
                scanf("%d",&inp);
                deleteNode(inp);
            }
            break;
            case 5:
            {
                printf("Enter the number to be searched. ");
                scanf("%d",&inp);
                NODE *nn = searchNode(inp);
                if(nn != NULL){
                    printf("%d Found!!!\n",inp);
                }
                else{
                    printf("%d Not Found!!!\n",inp);
                }
            }
            break;
            case 6:
            {
                printf("Exitting in 1,2,3....\n");
                exit(1);
            }
            break;
            default:
            {
                printf("****** WRONG INPUT ******\n");
                exit(1);
            }
        }
    }
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

NODE *searchNode(int k){
    NODE *h = root;
    while(h){
        if(h->key == k){
            return h;
        }
        if(k < h->key){
            h = h->left;
        }
        else{
            h = h->right;
        }
    }
    return NULL;
}

NODE *searchParent(int k){
    NODE *h = root;
    NODE *c = NULL;
    while(h){
        c = h;
        if(h->key == k){
            return c;
        }
        if(k < h->key){
            h = h->left;
        }
        else{
            h = h->right;
        }
    }
    return NULL;
}

void deleteNode(int k){
    NODE *x = searchNode(k);
    NODE *par = searchParent(k);
    NODE *y = NULL;
    if((x->left)&&(x->right)){
        NODE *p = NULL;
        y = x->right;
        p = x;
        while(y->left){
            p = y;
            y = y->left;
        }
        x->key = y->key;
        p->left = NULL;
        free(y);
    }
    if(!(x->left)&&!(x->right)){
        if(par->left == x){
            par->left = NULL;
        }
        else{
            par->right = NULL;
        }
        free(x);
    }
    if((x->left)&&!(x->right)){
        if(par->left == x){
            par->left = x->left;
        }
        else{
            par->right = x->left;
        }
        free(x);
    }
    if(!(x->left)&&(x->right)){
        if(par->right == x){
            par->right = x->right;
        }
        else{
            par->left = x->right;
        }
        free(x);
    }
    printf("The Number %d has been deleted from the tree!!\n",k);
}
