#include <stdio.h>

void bubbleSort(int val[], int wt[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (val[j] < val[j + 1]) {
                
                int tempVal = val[j];
                val[j] = val[j + 1];
                val[j + 1] = tempVal;

                int tempWt = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = tempWt;
            }
        }
    }
}

void knapsack(int values[], int weights[], int n, int capacity) {
    bubbleSort(values, weights, n);

    int totalValue = 0;
    int remainingCapacity = capacity;

    printf("Selected items:\n");

    for (int i = 0; i < n; i++) {
        if (weights[i] <= remainingCapacity) {
            printf("Item %d  Value: %d, Weight: %d\n", i + 1, values[i], weights[i]);
            totalValue += values[i];
            remainingCapacity -= weights[i];
        }
    }
    printf("\n");
    printf("Total value of selected items: %d\n", totalValue);
}

int main() {
    int values[] = {30, 25, 35, 40};
    int weights[] = {10, 8, 12, 6};
    int capacity = 20;
    int n = sizeof(values) / sizeof(values[0]);

    knapsack(values, weights, n, capacity);

    return 0;
}
