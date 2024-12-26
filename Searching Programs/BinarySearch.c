#include<stdio.h>
int main()
{
    int arr[10];
    int n,Beg = 0, End = 9, key, mid,i;
    printf("Enter the size of Array: \n");
	scanf("%d",&n);
	printf("Enter Array Elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
    printf("\nEnter the element you want to search:\n");
    scanf("%d", &key);
    int flag = 0;
    
    while (Beg <= End)
    {
        mid = (Beg + End) / 2;
        if (key < arr[mid])
        {
            End = mid - 1;
        }
        else if (key > arr[mid])
        {
            Beg = mid + 1;
        }
         else
        {
            printf("Element found at location %d\n", mid);
            flag = 1;
            break;
        }
    }
    
    if (!flag)
    {
        printf("Element not found\n");
    }
    
    return 0;
}

