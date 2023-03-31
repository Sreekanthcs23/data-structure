#include<stdio.h>
void selection();
int main()
{
	
	selection();
	return 0;
}
void selection()
{
	int i,j,index,n,small,a[20],com=0,ex=0;
	printf("\nEnter number of elements:");
	scanf("%d",&n);
	printf("\nEnter the arrray\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		small=a[i],index=i;
		for(j=i+1;j<n;j++)
		{
			com++;
			if(a[j]<small)
			{
				small=a[j];
				index=j;
			}
		}
		a[index]=a[i];
		a[i]=small;
		ex++;
	}
	printf("\nSorted array:");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("\nComaprisons=%d\nExchanges=%d",com,ex);
}
