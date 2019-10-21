/*
A example of shellsort;
 */

#include <stdio.h>

void shellsort(int * , int);

int main(void)
{
	int i;
	int a[10] = {9,1,2,5,7,4,8,6,3,5};
	shellsort(a,10);
	for(i = 0;i < 10;i++)
		printf("%d ",a[i]);
	return 0;
}



void shellsort(int * list , int len)
{


	int gap;
	int i,j,temp;
	gap = len/2;
	while( gap >= 1)
	{
		//set group with gap
		for(i = gap;i < len;i++)
		{
			j = 0;
			temp = list[i];

			//sorted for gap;
			for(j = i - gap;j >= 0 && list[j] > temp;j = j-gap)
			{
				list[j + gap] = list[j]; 
			}

			list[j + gap] = temp;
		}
		
		gap = gap/2;

	}









	return;
}