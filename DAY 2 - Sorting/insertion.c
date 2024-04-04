// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int arr[] = {5, 18, 8, 3, 1, 6};
    int n = sizeof(arr)/sizeof(int);
    
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){

                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}