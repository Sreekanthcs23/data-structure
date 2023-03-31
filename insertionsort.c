#include<stdio.h>
void insertion();
int main()
{
	insertion();
	return 0;
}

void insertion()
{
	int i,j,key,index,a[20],n,com=0,ex=0;
	printf("\nEnter number of elements:");
	scanf("%d",&n);
	printf("\nEnter the arrray");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		key=a[i],index=i;
		for(j=i-1;j>=0;j--)
		{
			com++;
			if(key<a[j])
			{
				a[index]=a[j];
				a[j]=key;
				index=j;
				ex++;
			}
			else
				break;
		}
	}
	printf("\nSorted array:");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("\nComaprisons=%d\nExchanges=%d",com,ex);
}
