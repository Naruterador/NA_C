/*
Counting the number of the digit.
 */
#include <stdio.h>

int main(void)
{
	return 0;
}


int getfigures(int n)
{
	int i = 0;
	while(n)
	{
		n = n/10;
		i++;
	}

	return i;
}
