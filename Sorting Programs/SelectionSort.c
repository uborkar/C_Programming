#include <stdio.h>

int i,j,temp,minindex;
 void selectionsort(int arr[],int n){
    for(i=0; i<n-1; i++)
    {
        minindex=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        //swap logic
        temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
    }

int main()
{
    int arr[10],n,i;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    
    printf("Enter array Elements:\n \t",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    selectionsort(arr,n);
    
    printf("Sorted Array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
    return 0;
}
