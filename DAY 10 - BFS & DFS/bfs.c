#include <stdio.h>

int q[10], f = -1, r = -1;

int isEmpty() {
    if (f == r) {
        return 1;
    } else {
        return 0;
    }
}

void Insert(int v) {
    q[++r] = v;
}

int Del() {
    int v;
    v = q[++f];
    return v;
}

int main() {
    int i, j, n = 7, visited[10] = {}, v;
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

    visited[0] = 1;
    Insert(0);
    while (!isEmpty()) {
        v = Del();
        printf("visited %d\n", v);
        for (i = 0; i < n; i++) {
            if (visited[i] != 1 && G[v][i] == 1) {
                visited[i] = 1;
                Insert(i);
            }
        }
    }
    return 0;
}