// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int arr[] = {5, 18, 8, 3, 1, 6};
    int n = sizeof(arr)/sizeof(int);
    
    for(int i=0; i<n-1; i++){
        int min = arr[i];
        int index = i;
        for(int j=i+1; j<n; j++){
            if(min > arr[j]){
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}