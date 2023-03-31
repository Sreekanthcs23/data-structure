#include<stdio.h>
void bubble();
void insertion();
void selection();
int main()
{
	int s;
	printf("Enter 1 for bubble sort\n2 for insertion sort\n3 for selection sort\n");
	scanf("%d",&s);
	switch(s)
	{
		case 1: bubble();
			break;
		case 2: insertion();
			break;
		case 3: selection();
			break;
	}
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
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
