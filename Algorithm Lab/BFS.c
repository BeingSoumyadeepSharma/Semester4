#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct Node{
    int key;
    struct Node *next;    
}NODE;
NODE *head = NULL;
int am[MAX][MAX];
int visited[MAX];
int n,i,j;

void enqueue(int);
int dequeue();
void bfs(int);

int main(void){
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        visited[i] = 0;
    }

    printf("\nEnter graph data in matrix form: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&am[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d",&v);
    printf("\nThe Nodes which are reached:\n");
    bfs(v);
    printf("\n");

    for(i=1;i<=n;i++){
        if(!visited[i]){
            printf("\nBFS is not possible. Not all nodes are reachable");
            break;
        }
    }
    printf("\n");

    return 0;
}

void enqueue(int k){
    NODE *t = (NODE *)malloc(sizeof(NODE));
    NODE *y;
    t->key = k;
    t->next = NULL;

    if(!head){
        head = t;
        return;
    }

    y = head;
    while(y->next){
        y = y->next;
    }
    y->next = t;
}

int dequeue(){
    int k;
    NODE *x = head;

    if(head == NULL){
        printf("The Queue is Empty\n");
        exit(0);
    }

    head = head->next;
    x->next = NULL;
    k = x->key;
    free(x);
    return k;
}

void bfs(int s){
    int vs,ws;
    visited[s] = 1;
    enqueue(s);
    while(head != NULL){
        vs = dequeue();
        printf("%d\t",vs);
        for(ws=1;ws<=n;ws++){
            if(am[vs][ws] && !visited[ws]){
                visited[ws] = 1;
                enqueue(ws);
            }
        }
    }
}
