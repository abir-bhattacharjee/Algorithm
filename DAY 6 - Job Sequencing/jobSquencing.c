#include<stdio.h>

struct job{
    int id, deadline, profit;
};

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void jobSequencing(struct job a[], int n){
    int maxDeadline = 0;
    for(int i=0; i<n; i++){
        if(a[i].deadline > maxDeadline){
            maxDeadline = a[i].deadline;
        }
    }

    int timeslots[maxDeadline];
    for(int i=0; i<maxDeadline; i++){
        timeslots[i] = -1;
    }

    int totalProfit = 0;
    for(int i=0; i<n; i++){
        for(int j = min(maxDeadline, a[i].deadline) - 1; j>=0; j--){
            if(timeslots[j] == -1){
                timeslots[j] = a[i].id;
                totalProfit += a[i].profit;
                break;
            }
        }
    }

    printf("Total Profit: %d\n", totalProfit);
    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        printf("%d ", timeslots[i]);
    }
    
}

int main(){
    
    struct job a[4] = {{1, 2, 30},{2, 3, 20},{3, 2, 50},{4, 1, 25}};
    
    // for(int i=0; i<4; i++){
    //     printf("enter id, deadline, profit for %d job :",i+1);
    //     scanf("%d%d%d",&a[i].id,&a[i].deadline,&a[i].profit);
    // }

    for(int i=0; i<4-1; i++){
        for(int j=0; j<4-i-1; j++){
            if(a[j].profit < a[j+1].profit){
                
                struct job temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // for(int i=0; i<4;i++){
    //     printf("%d %d %d\n", a[i].id, a[i].deadline, a[i].profit);
    // }

    jobSequencing(a, 4);

    return 0;
}
