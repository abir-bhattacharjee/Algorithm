#include<stdio.h>

int main() {
    // for user input
    // int matrix[50][50];
    // printf("Enter number of vertices in graph: ");
    // int n;
    // scanf("%d", &n);
    // matrix[0][0] = 0;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("Enter cost of [%d][%d]: ", i, j);
    //         scanf("%d", &matrix[i][j]);
    //     }
    // }

    int matrix[7][7] = {{0, 0, 1, 2, 0, 0, 0},
                        {0, 0, 2, 0, 0, 3, 0},
                        {1, 2, 0, 1, 3, 0, 0},
                        {2, 0, 1, 0, 0, 0, 1},
                        {0, 0, 3, 0, 0, 2, 0},
                        {0, 3, 0, 0, 2, 0, 1},
                        {0, 0, 0, 1, 0, 1, 0}};

    int cost[10][10];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (matrix[i][j] != 0) 
                cost[i][j] = matrix[i][j]; 
            else 
                cost[i][j] = 999;
        }
    }

    int source = matrix[0][0];
    int nextnode, count=0;

    int dist[10], pred[10], visited[10];
    for(int i=0; i<7; i++){
        dist[i] = cost[source][i];
        pred[i] = source;
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;
    count = 1;

    while(count < 7-1){
        int mindist = 999;
        for(int i=0; i<7; i++){
            if(dist[i] < mindist && !visited[i]){
                mindist = dist[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(int i=0; i<7; i++){
            if(!visited[i]){
                if(mindist + cost[nextnode][i] < dist[i]){
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }

        count++;
    }

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < 7; i++)
        printf("%d \t\t %d\n", i, dist[i]);

    return 0;
}
