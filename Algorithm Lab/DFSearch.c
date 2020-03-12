#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int am[MAX][MAX];
int visited[MAX];
int n,i,j,c=1,keep=0;

void dfs(int,int);

int main(void){
    int v,k;
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
    printf("\nEnter the vertex to be searched: ");
    scanf("%d",&k);
    dfs(v,k);
    if(keep == 0){
        printf("Vertex Not Found!!!\n");
        exit(0);
    }
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

void dfs(int s,int num){
    int ws;
    visited[s] = 1;
    if(s == num){
        printf("Vertex found in vertex traversal number-%d\n",c);
        keep = 1;
        exit(0);
    }
    for(ws=1;ws<=n;ws++){
        c++;
        if(am[s][ws] && !visited[ws]){
            dfs(ws,num);
        }
    }
}
