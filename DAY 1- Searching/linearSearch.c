#include<stdio.h>

void linSearch(int arr[], int size, int item) {
    int found = 0; 

    for(int i = 0; i < size; i++) {
        if(item == arr[i]) {
            found = 1;
            break; 
        }
    }

    if(found) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
}

int main() {
    int arr[50], size, item;
    printf("Enter size of array : ");
    scanf("%d", &size);

    printf("Enter elements of array : ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search : ");
    scanf("%d", &item);

    linSearch(arr, size, item);

    return 0;
}
