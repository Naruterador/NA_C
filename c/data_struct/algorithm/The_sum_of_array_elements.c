/*
Calculating the sum of one dimension of elements;
 */


#include <stdio.h>

float sum_array(float *,int);

int main(void)
{
	float sum;
	float a[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1};
	sum = sum_array(a,10);
	printf("%.2lf\n",sum);        //controling the outputting precision as 2;

	return 0;
}


float sum_array(float * ar,int length)
{
	int i;
	float sum = 0;

	for(i = 0;i < length;i++)
	{
		sum = sum+ar[i];
	}

	return sum;
}