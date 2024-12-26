#include <stdio.h>

void bubblesort(int arr[],int n, int *swapcount)
{	int i,j,temp;
	*swapcount=0;
    for (i=0; i<n-1; i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swapcount)++;
            }
        }
    }
}

int main()
{
	int i,j,swapcount;
    int arr[7] = {7, 1, 4, 12, 67, 33, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubblesort(arr,n,&swapcount);
    printf("Sorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
	
	printf("Number of swaps performed: %d\n", swapcount);
    return 0;
}
