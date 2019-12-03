/*
Inputting the three numbers and ordering it; 
 */



#include <stdio.h>


int main(void)
{
	int a,b,c;
	int t = 0;
	printf("Please intputting three numbers: a,b,c\n");
	scanf("%d,%d,%d",&a,&b,&c);

	if(a < b)
	{
		t = a;
		a = b;
		b = t;
	}

	if(a < c)
		t = a;
		a = c;
		c = t;

	if(b < c)
	{
		t = b;
		b = c;
		c = t;
	}


	printf("%d\n%d\n%d\n",a,b,c);


	return 0;
}

