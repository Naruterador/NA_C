/*
Tower Hanoi express;
 */
#include <stdio.h>

void hanoi(int,char,char,char);

int main(void)
{

	char A = 'A';
	char B = 'B';
	char C = 'C';
	int n;
	printf("Please input the number of slate:\n");
	scanf("%d",&n);
	hanoi(n,A,B,C);
	return 0;
}


void hanoi(int n,char A,char B,char C)
{
	if( n == 1)
		printf("Moving the NO.%d slate from %c to %c\n",n,A,C);
	else
	{
	 	hanoi(n-1,A,C,B);
	 	printf("Moving the NO.%d slate from %c to %c\n",n,A,C);
	 	hanoi(n-1,B,A,C);
	}
}