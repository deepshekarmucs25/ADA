#include<stdio.h>

void krushkal(){
    int n, i, j, min, mincost = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    int parent[n];

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
        parent[i] = -1; // Initialize all vertices as separate sets
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for(i = 0; i < n - 1; i++){
        min = 9999;
        int x, y;

        for(j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(graph[j][k] && find(parent, j) != find(parent, k)){
                    if(graph[j][k] < min){
                        min = graph[j][k];
                        x = j;
                        y = k;
                    }
                }
            }
        }

        printf("%d - %d\n", x, y);
        mincost += min;
        union_sets(parent, x, y); // Union the sets of the two vertices
    }

    printf("Minimum Cost: %d\n", mincost);
}
int main(){
    krushkal();
    return 0;
}