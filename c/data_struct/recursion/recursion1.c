/*
Using recursion to wirte a program as 1+2+3+4+......10;
 */

#include <stdio.h>

int f(int i)
{
	int sum;

	if( i == 1)
		return i;
	else
	{
		sum = i + f(i-1);
		return sum;

	}	

}



int main(void)
{

	int i;
	i = f(10);
	printf("%d\n",i);

	return 0;
}