#include<stdio.h>

void linSearch(int arr[], int size, int item) {
    int found = 0; // Variable to track whether the item is found or not

    for(int i = 0; i < size; i++) {
        if(item == arr[i]) {
            found = 1;
            break; // Exit the loop once the item is found
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
