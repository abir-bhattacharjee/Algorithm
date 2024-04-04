#include<stdio.h>

int find(int i, int parent[]) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j, int parent[]) {
    if (i != j) {
        parent[i] = j;
        return 1;
    }
    return 0;
}

int main() {
    int matrix[50][50];
    printf("Enter number of vertices in graph: ");
    int n;
    scanf("%d", &n);
    matrix[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Enter cost of [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int cost[n][n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == 0) 
                cost[i][j] = 999; 
            else 
                cost[i][j] = matrix[i][j];
        }
    }

    int ne = 0;
    int mincost = 0;
    int parent[10] = {0};
    int a, b, v, u;

    while (ne < n - 1) {
        int min = 999;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u, parent);
        v = find(v, parent);

        if (uni(u, v, parent)) {
            printf(" %d <--> %d  : %d\n", a,b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = 999;
    }
    printf("Mincost : %d\n", mincost);
    return 0;
}
