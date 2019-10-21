/*
A example of ascending order sort by quick sorting;
 */


#include <stdio.h>


void QuickSort(int * , int , int);
int Findpos(int * , int , int);

int main(void)
{
	int a[8] = {9,0,8,10,-5,2,13,7};
	QuickSort(a,0,7);

	for (int i = 0;i < 8;i++)
		printf("%d ",a[i]);


	return 0;
}


void QuickSort(int * array, int low , int high)
{
	int pos;

	if(low < high)
	{
		pos = Findpos(array,low,high);
		QuickSort(array,low,pos-1);
		QuickSort(array,pos+1,high);
	}
	return;
}



int Findpos(int * array , int low , int high)
{

	int val = array[low];

	while (low < high)
	{
		while(low < high && array[high] >= val)
			high--;
		array[low] = array[high];

		while(low < high && array[low] <= val)
			low++;
		array[high] = array[low];

	}
	array[low] = val;

	return low;
}