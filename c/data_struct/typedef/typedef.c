/*
AN example of how to use function of typedef.
 */


#include <stdio.h>
#include <string.h>

typedef int tYint;

typedef struct student
{
	int sid;
	char name[50];
	char gender;
} ST;

typedef struct student1
{

	int sid;
	char name[50];
	char gender;
} * PST;                                       //PST equal to struct student1


/*
typedef struct student2
{
	int sid;
	char name[50];
	char gender;
} * PST,ST1;

Vc++ complier can define the sturct like this.

*/




int main(void)
{
	tYint i = 2;

	ST st;
	st.sid = 1;

	struct student1 st1;
	PST ps = &st1;
	strcpy(ps->name,"john");

	printf("%d\n%d\n%s\n",i,st.sid,ps->name);

	return 0;
}