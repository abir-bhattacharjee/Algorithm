#include<stdio.h>

void binarySearch(int arr[], int size, int item) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == item) {
            printf("Found\n");
            return; 
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Not found\n");
}

int main() {
    int arr[50], size, item;
    printf("Enter size of array : ");
    scanf("%d", &size);

    printf("Enter elements of array in sorted order: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search : ");
    scanf("%d", &item);

    binarySearch(arr, size, item);

    return 0;
}
