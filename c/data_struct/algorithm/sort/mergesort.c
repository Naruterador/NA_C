/*
A example of merge sort;
 */


#include <stdio.h>
#include <stdlib.h>

void Merge(int *,int , int, int);
void MergeSplit(int *,int,int);
void Mergesort_bottom_to_top(int *,int);
void Mergesort_top_to_bottom(int *,int,int);





int main(void)
{
	int a[10] = {9,1,5,3,4,2,6,8,7,10};

<<<<<<< HEAD
	Mergesort(a,10);
=======
	Mergesort_bottom_to_top(a,9);
>>>>>>> 63849542da9608340d59eed3130138bf54113974

	for(int i = 0;i < 9;i++)
		printf("%d ",a[i]);

	return 0;
}



void Merge(int * list,int low,int mid,int high)
{
	int i,j;
	int k = 0;
	i = low;
	j = mid + 1;

	int * list2 =(int *)malloc(sizeof(int) * (high - low + 1));

	while(i <= mid && j <= high)
	{
		if(list[i] <= list[j])
		{
			list2[k] = list[i];
			i++;
			k++;
		}else{
			list2[k] = list[j];
			j++;
			k++;
		}
	}

	while(i <= mid)
	{
		list2[k] = list[i];
		i++;
		k++;
	}

	while(j <= high)
	{
		list2[k] = list[j];
		j++;
		k++;
	}

	for(k = 0,i = low;i <= high;i++,k++) //mark
		list[i] = list2[k];
		
	/*
	for(i = 0;i < k;i++)
		list[low + i] = list2[i];
	*/

	free(list2);
}


//From bottom to top
void MergeSplit(int * list,int gap,int len)
{
	int i;

	for(i = 0;i + 2 * gap - 1 < len;i = i + 2 * gap)
		Merge(list,i,i + gap - 1,i + 2 * gap - 1);

<<<<<<< HEAD
	if(i + gap - 1 < len - 1)
		Merge(list,i,i + gap - 1,len - 1);
=======
	if(i + gap - 1 < len - 1 )
		Merge(list,i,i + gap -1,len - 1);
>>>>>>> 63849542da9608340d59eed3130138bf54113974
}


void Mergesort_bottom_to_top(int * list,int len)
{

	int gap;

	for(gap = 1;gap < len;gap = 2 * gap)
		MergeSplit(list,gap,len);

}



/*
//From top to bottom;
void Mergesort_top_to_bottom(int * list,int low,int high)
{
	if(list == NULL || low >= high)
		return;

	int mid;
	mid = (low + high) / 2;
	Mergesort_top_to_bottom(list,low,mid);
	Mergesort_top_to_bottom(list,mid + 1,high);
	Merge(list,low,mid,high);
}
*/