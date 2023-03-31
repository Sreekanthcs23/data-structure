#include<stdio.h>
void bubble();
int main()
{
	
	bubble();
	return 0;
}
void bubble()
{
	int a[20],i,j,temp,n,com=0,ex=0;
	printf("\nEnter number of elements:");
	scanf("%d",&n);
	printf("\nEnter the arrray");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			com++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				ex++;
			}
		}
	}
	printf("\nSorted array:");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("\nComaprisons=%d\nExchanges=%d",com,ex);
}
