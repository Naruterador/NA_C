/*
Using recursion to express a program as !n=1x2x3x4x5.............x100;

!n = n * !(n-1)


 */

#include <stdio.h>


int f(int i)
{
	int p = 1;

	if(i == 1)
		return i;
	else
	{
		p = i * f(i-1);
		return p;
	}

}






int main(void)
{
	int i;
	i = f(4);
	printf("%d\n",i);


	return 0;
}