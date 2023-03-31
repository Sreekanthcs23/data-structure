#include<stdio.h>
void linear();
void binary();
int main()
{
	int s;
	printf("Enter 1 for linear search, 2 for binary search\n");
	scanf("%d",&s);
	switch(s)
	{
		case 1: linear();
		         break;
		case 2: binary();
			 break;
	}
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
		
void binary()
{
	int b[20],j,p,ele,l,r,m,f=0;
	printf("Enter the number of elements:");
	scanf("%d",&p);
	printf("\nEnter the array\n");
	for(j=0;j<p;j++)
		scanf("%d",&b[j]);
	printf("\nEnter the element to be found:");
	scanf("%d",&ele);
	l=0;
	r=p-1;
	m=(l+r)/2;
	while(l<=r)
	{
		if(ele>b[m])
		{
			l=m+1;
		}
		else if(ele==b[m])
		{
			printf("\nElement found at index %d",m);
			f=1;
			break;
		}
		else
			r=m-1;
		m=(l+r)/2;
	}
	if(f==0)
		printf("\nElement not present in the array");
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
		
		
		
		
		
		
		
		
		
