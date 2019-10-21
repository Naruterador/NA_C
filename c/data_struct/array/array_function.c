/*
Creating the function to operate the array what user input;
 */

#include <stdio.h>
#include <stdlib.h>

struct arr
{
	int * pBase;
	int len;
	int ce;
};


void init_arr(struct arr *,int length);  //initializing the arr;
bool append_arr(struct arr *,int elementvalue);
bool insert_arr(struct arr *,int position,int elementvalue);
bool delete_arr(struct arr *,int position,int * pVal);
int get(struct arr * arr,int pos);
bool is_empty_arr(struct arr *);
bool is_full_arr(struct arr *);
void sort_arr(struct arr *);
void show_arr(struct arr *);
void inversion_arr(struct arr *);

int main(void)
{

	struct arr array;
	int val;
	int elvalue;
	init_arr(&array,6);
	append_arr(&array,60);
	append_arr(&array,100);
	append_arr(&array,36);
	append_arr(&array,88);
	append_arr(&array,28);
	append_arr(&array,71);
	elvalue = get(&array,3);
	printf("%d\n",elvalue);
	//show_arr(&array);

	return 0;
}


void init_arr(struct arr * Parr,int length)
{
	Parr->pBase = (int *)malloc(sizeof(int) * length);
	if(NULL == Parr->pBase)
	{
		printf("Failed to assign ram spaces!\n");
		exit(-1);
	}
	Parr->len = length;
	Parr->ce = 0;
	return;
}

bool is_empty_arr(struct arr * Parr)
{
	if(Parr->ce == 0)
		return true;
	else
		return false;
}

bool is_full_arr(struct arr * Parr)
{
	if(Parr->ce == Parr->len)
		return true;
	else
		return false;
}

void show_arr(struct arr * Parr)
{
	int i;
	if(is_empty_arr(Parr))
		printf("The array has no element in it!\n");
	else
	{
		for(i = 0;i < Parr->len;i++)
			printf("%d\n",Parr->pBase[i]);

	}
	return;
}

bool append_arr(struct arr * Parr,int elementvalue)
{
	if(is_full_arr(Parr))
		return false;
	else
	{
		Parr->pBase[Parr->ce] = elementvalue;
		(Parr->ce)++;
		return true;
	}
}

bool insert_arr(struct arr * pArr,int position,int elementvalue)
{
	int i,j;
	if(is_full_arr(pArr))
		return false;
	
	if(position < 0 || position > pArr->ce + 1)
		return false;

	for(i = pArr->ce,j = pArr->ce-1;i > position;i--,j--)
		pArr->pBase[i] = pArr->pBase[j];

	pArr->pBase[position] = elementvalue;
	pArr->ce++;
	return true;
}

bool delete_arr(struct arr * pArr,int position,int * pVal)
{
	int i;
	if(is_empty_arr(pArr))
		return false;

	if(position < 0 || position > pArr->ce)
		return false;

	*pVal = pArr->pBase[position];
	for(i = position;i < pArr->ce - 1;i++)
		pArr->pBase[i] = pArr->pBase[i+1];

	pArr->len--;
	return true;
}

void inversion_arr(struct arr * pArr)
{
	int t = 0;
	int i,j;

	for(i = 0,j = pArr->ce -1;i < (pArr->ce/2);i++,j--)
	{
		t = pArr->pBase[j];
	    pArr->pBase[j] = pArr->pBase[i];
	    pArr->pBase[i] = t;
	}
}

void sort_arr(struct arr * pArr)
{
	int i,j,t;
	for(i = 0;i < pArr->ce - 1;i++)
		for(j = 0;j < (pArr->ce) - i - 1;j++)
			if(pArr->pBase[j+1] > pArr->pBase[j])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[j+1];
				pArr->pBase[j+1] = t;
			}
}


int get(struct arr * pArr,int position)
{
	if(position < 0 || position > pArr->ce)
		return 0;
	return pArr->pBase[position];
}