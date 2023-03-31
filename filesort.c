#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
struct student
{
	char name[20];
	char lname[10];
	float height;
	float weight;
}std1[20],std2[20];

void merge(struct student arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	struct student L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
		
	i = 0; 
	j = 0;
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i].height < R[j].height) {
			arr[k] = L[i];
			i++;
		}
		else if (L[i].height > R[j].height) {
			arr[k] = R[j];
			j++;
		}
		else if(L[i].weight < R[i].weight)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(struct student arr[], int l, int r)
{
	if (l < r) {
	
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void quicksort(struct student arr[],int first,int last)
{
   int i, j, pivot;
   struct student temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j)
      {
         while((arr[i].height<=arr[pivot].height) && i<last)
            i++;
         while(arr[j].height>arr[pivot].height)
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      
      }
	temp=arr[pivot];       
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
     

   }
}

int main()
{
	int i=0;
	FILE *fptr = fopen("file.txt","r");
	while(fscanf(fptr,"%s %s %f %f",std1[i].name,std1[i].lname,&std1[i].height,&std1[i].weight)!=EOF)
	{
		strcpy(std2[i].name,std1[i].name);
		strcpy(std2[i].lname,std1[i].lname);
		std2[i].height = std1[i].height;
		std2[i].weight = std1[i].weight;
		i++;
	}
	fclose(fptr);
	double t;
	clock_t start,end;
	start = clock();
	mergeSort(std1,0,i-1);
	end = clock();
	t = (double) (end-start);
	FILE *wptr = fopen("mergesort.txt","w");
	
	for(int j=0;j<i;j++)
	{
		fprintf(wptr,"%s %s %f %f\n",std1[j].name,std1[j].lname,std1[j].height,std1[j].weight);
	}
	fprintf(wptr,"Time taken: %f",t);
	fclose(wptr);
	
	start = clock();
	quicksort(std2,0,i-1);
	end = clock();
	t = (double) (end-start); 
	FILE *wptr2 = fopen("quicksort.txt","w");
	
	for(int j=0;j<i;j++)
	{
		fprintf(wptr2,"%s %s %f %f\n",std2[j].name,std2[j].lname,std2[j].height,std2[j].weight);
	}
	fprintf(wptr2,"Time taken: %f",t);
	fclose(wptr2);
	return 0;
}






