/*
A example of direct insertion sort;
 */

#include <stdio.h>

void Insertionsort(int *,int);

int main(void)
{
	int a[5] = {3,89,72,43,1};

	Insertionsort(a,5);

	for(int i = 0;i < 5;i++)
		printf("%d ",a[i]);



	return 0;
}


void Insertionsort(int * arr,int len)
{
	int i;
	int j;
	int temp;

	for(i = 1;i < len;i++)
		for(j = 0;j < i;j++)
			if(arr[j]>arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	return;
}