#include <stdio.h>

int getMax(int arr[], int size) {
    int max = arr[0],i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countingSort(int arr[], int size, int place) {
    int output[size],i;
    int count[10] = {0};
    // Count occurrences of digits
    for (i = 0; i < size; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }
    // Calculate cumulative count
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    // Copy the sorted elements back to the original array
    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);
    int i,place;
    for (place = 1; max / place > 0; place *= 10) {
        countingSort(arr, size, place);
    }
}
// Function to print the array
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[10],i;
    printf("Enter 10 elements:\n");
    for (i = 0; i < 10; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array:\n");
    printArray(arr, 10);
    radixSort(arr, 10);
    printf("Sorted array:\n");
    printArray(arr, 10);
    return 0;
}

