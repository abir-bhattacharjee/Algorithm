#include <stdio.h>

void bubbleSort(int profit[], int weight[], double ratio[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            if (ratio[j] < ratio[j + 1]) {
                 
                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;

                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;
            }
        }
    }
    
}


double fractionalKnapsack(int W, int profit[], int weight[], int n) {
    
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)profit[i] / weight[i];
    }

    
    bubbleSort(profit, weight, ratio, n);

    double totalProfit = 0.0;
    int currentWeight = 0;

    
    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= W) {
            totalProfit += profit[i];
            currentWeight += weight[i];
        } else {
            double fraction = (double)(W - currentWeight) / weight[i];
            totalProfit += profit[i] * fraction;
            break; 
        }
    }

    return totalProfit;
}

int main() {
    int profit[] = {6, 5, 4};
    int weight[] = {5, 4, 3};
    int n = sizeof(profit) / sizeof(profit[0]);
    int W = 7;

    double result = fractionalKnapsack(W, profit, weight, n);

    printf("Maximum profit in Knapsack = %.2f\n", result);

    return 0;
}
