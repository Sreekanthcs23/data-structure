#include<stdio.h>
void linear();
int main()
{
	linear();
	
	return 0;
}
void linear()
{
	int a[20],i,n,elem,flag=0;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the element to be found:");
	scanf("%d",&elem);
	for(i=0;i<n;i++)
	{
		if(elem==a[i])
		{
			printf("\nElement is found at index %d",i);
			flag++;
			break;
		}
	}
	if(flag==0)
		printf("\nElement not present in the array");
}
