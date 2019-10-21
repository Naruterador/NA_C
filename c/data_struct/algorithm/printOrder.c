/*
Outputing the each number of one digit orderly.
 */





#include <stdio.h>

int main(void)
{
	return 0;
}




void printOrder(int n)
{
	int power = 1;
	int len = getfigures(n);
	int i;
	for(i = 0;i < len-1;i++)
	{
		power*=10;

	}
	while(n)
	{
		printf("%d\n",n/power);

		n = n % power;

		power = power/10;

	}

}
