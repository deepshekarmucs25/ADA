#include <stdio.h>

void prims(){
    int n, i, j, min, mincost = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    int selected[n];

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
        selected[i] = 0; // Initialize all vertices as not selected
    }

    selected[0] = 1; // Start from the first vertex

    printf("Edges in the Minimum Spanning Tree:\n");
    for(i = 0; i < n - 1; i++){
        min = 9999;
        int x, y;

        for(j = 0; j < n; j++){
            if(selected[j]){
                for(int k = 0; k < n; k++){
                    if(!selected[k] && graph[j][k]){
                        if(graph[j][k] < min){
                            min = graph[j][k];
                            x = j;
                            y = k;
                        }
                    }
                }
            }
        }

        printf("%d - %d\n", x, y);
        mincost += min;
        selected[y] = 1; // Mark the vertex as selected
    }

    printf("Minimum Cost: %d\n", mincost);
}
int main(){
    prims();
    return 0;
}