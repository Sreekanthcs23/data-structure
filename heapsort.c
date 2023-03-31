#include<stdio.h>

int arr[30];

void heapify(int l)
{
	for(int i=(l/2-1);i>=0;i--)
	{
		int largest = i;
		int a = 2*i+1;
		int b = 2*i+2;
		if((a<l) && (arr[a]>arr[i]))
			largest = a;
		if((b<l) && (arr[b]>arr[largest]))
			largest = b;
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
	}
}

void sort(int l)
{
	for(int i=l;i>1;i--)
	{
		heapify(i);
		int temp = arr[0];
		arr[0] = arr[i-1];
		arr[i-1] = temp;
	}
}

void binary(int ele,int p)
{
	int l,r,m,f=0;
	l=0;
	r=p-1;
	m=(l+r)/2;
	while(l<=r)
	{
		if(ele>arr[m])
		{
			l=m+1;
		}
		else if(ele==arr[m])
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

int main()
{
	int l,ele;
	printf("Enter the number of terms:");
	scanf("%d",&l);
	printf("Enter the numbers:\n");
	for(int i=0;i<l;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(l);
	printf("Sorted array:\n");
	for(int i=0;i<l;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\nEnter the element to be found:");
	scanf("%d",&ele);
	binary(ele,l);
	return 0;
}


















