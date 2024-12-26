#include<stdio.h>
int main()
{
	int arr[10];
	int flag,i,key,n;
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
	printf("\nEnter the key Element you want to search: \n");
	scanf("%d",&key);
	
	for(i=0;i<10;i++)
	{
		if(key==arr[i])
		{
			flag=i+1;
			break;
		}
		else
		flag=0;
	}
	if(flag!=0)
	{
		printf("Key found at position %d \n",flag);
	}
	else{
		printf("Key not found!!");
	}
}
