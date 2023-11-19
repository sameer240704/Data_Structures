#include<stdio.h>
#include<conio.h>
#define MAX 100

void Sort(int arr[], int n);
void main()
{
	int n,i,a[MAX];

	printf("Enter Number of Element to be Sort : ");
	scanf("%d",&n);
	printf("\n Enter %d Elements in Array to Sort : ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n Elements Before Sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	Sort(a,n);
	printf("\nElements after Sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	getch();
}



void Sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
	key = arr[i];
	j = i - 1;
	while (j >= 0 && arr[j] > key)
	{
	    arr[j + 1] = arr[j];
	    j = j - 1;
	}
	arr[j + 1] = key;
    }
}

