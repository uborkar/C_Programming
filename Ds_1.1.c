#include <stdio.h>
int main()
{
	int a[10];
	int sum_of_sqr=0;
	printf("Enter 10 integers:\n ");
	for (int i=0;i<10;i++)
	{
		printf("Element %d: ",i + 1);
		scanf("%d", &a[i]);  
	}
	
	for(int i=0;i<10;i++)
	{
		sum_of_sqr +=a[i] * a[i];
	}
	
	printf("Sum of squares: %d\n", sum_of_sqr);
	
	return 0;
}