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

void dfs(int);

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
    dfs(v);
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

void dfs(int s){
    int ws;
    visited[s] = 1;
    printf("%d\t",s);    
    for(ws=1;ws<=n;ws++){
        if(am[s][ws] && !visited[ws]){
            dfs(ws);
        }
    }
}
