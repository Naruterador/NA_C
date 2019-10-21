#include <stdio.h>


int getSumNum(int * arr,int n,int Sum)
{
    int i,j;
    for(i = 0, j = n-1; i < j ; )
    {
        if(arr[i] + arr[j] == Sum)
        {
             printf ("i = %d, j = %d",arr[i],arr[j]);
         	 return 0;
        }
        else if(arr[i] + arr[j] < Sum)
            i++;
        else
            j--;
    }
    printf("Can not pair any numbers!");
    return 0;
}





int main(void)
{
	int arr[7] = {1,4,5,6,7,8,11};
	int sum = 10;
	int n = 7;
	getSumNum(arr,n,sum);
	return 0;
}