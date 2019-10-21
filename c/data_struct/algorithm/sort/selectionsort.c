/*
A example of selection sort;
 */


#include <stdio.h>

void selectionsort(int *,int);

int main(void)
{

	int a[10] = {9,1,2,5,7,4,8,6,3,5};

	selectionsort(a,10);

	int i;
	for (i = 0;i < 10;i++)
		printf("%d ",a[i]);
	return 0;
}




void selectionsort(int * arr,int len)
{
	int temp = 0;
	int index = 0;
	int i,j;
	for(i = 0;i < len -1;i++)
	{
		index = i;
		for(j = i+1;j < len;j++)
		{

			if(arr[index] > arr[j])
				index = j;

		}

		temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;

	}	
}