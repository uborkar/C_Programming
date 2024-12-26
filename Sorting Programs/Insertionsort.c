#include <stdio.h>

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[10],n,i;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter size of array: \n");
    scanf("%d",&n);
    printf("Enter array Elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array: \n");
    printArray(arr, size);
    insertionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
    return 0;
}

