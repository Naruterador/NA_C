/*
A example of heapsort;
 */



#include <stdio.h>

void heapAdjust(int *,int , int);
void heapsort(int * ,int);

int main(void)
{
	int i;
	
	int a[10] = {1,3,4,5,2,6,9,7,8,0};

	heapsort(a,10);

	for(i = 0;i < 10;i++)
		printf("%d ",a[i]);

	return 0;
}




void heapAdjust(int * list , int parent , int len)
{
	int temp,child;
	temp = list[parent];
	//the position of the left's child
	child = 2 * parent + 1;

	while(child < len)
	{
		//compared the left's child and right's child;
		if(child + 1 < len && list[child] < list[child + 1])
			child++;

		if(temp >= list[child])
			break;

		list[parent] = list[child];


		//maked the letf's child as parent and carried on running the program;
		parent = child;
		child = 2 * child + 1;

	}

	list[parent] = temp;
}


void heapsort(int * list, int len)
{
	int i,j;
	int temp;


	//Create a heap;
	for(i = len / 2;i >= 0;i--)
		heapAdjust(list,i,len);



	//sorting
	for(j = len - 1;j > 0;j--)
	{
		//exchanging the value of the first element and the terminal element;
		temp = list[j];
		list[j] = list[0];
		list[0] = temp;
		heapAdjust(list,0,j);
	}



}