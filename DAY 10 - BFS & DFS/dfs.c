#include <stdio.h>

int visited[10] = {};

void DFS(int G[7][7], int v, int n) {
    int i;
    printf("visited %d\n", v);
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (visited[i] != 1 && G[v][i] == 1) {
            DFS(G, i, n);
        }
    }
}

int main() {
    int  i, j, n = 7;
    // printf("Enter the adjacency matrix:\n");
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
    //         printf("Insert value at[%d] [%d]: ", i, j);
    //         scanf("%d", &G[i][j]);
    //     }
    // }

    int G[7][7] = {{0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0}};

    printf("DFS traversal starting from node 0:\n");
    DFS(G, 0, n);

    return 0;
}
