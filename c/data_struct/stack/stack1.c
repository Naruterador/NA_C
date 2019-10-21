/*
Operating the stack;
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

	int data;
	struct Node * pNext;

} * pNode;

typedef struct stack
{
	pNode pTop;
	pNode pBottom;
}* S;


void init_stack(S);
void push_stack(S,int);
void traverse_stack(S);
bool pop_stack(S,int *);
bool is_empty(S);
void clear_stack(S);

int main(void)
{	
	int val;
	struct stack S;
	init_stack(&S);
	push_stack(&S,1);
	push_stack(&S,2);
	push_stack(&S,3);
	push_stack(&S,4);
	traverse_stack(&S);
	return 0;
}

void init_stack(S pS)
{
	pS->pTop =(pNode)malloc(sizeof(struct Node));
	if(NULL == pS->pTop)
	{
		printf("Assigning the ram space failed!");
		exit(-1);
	}

	pS->pBottom = pS->pTop;
	pS->pTop->pNext = NULL;
}

void push_stack(S pS,int val)
{
	pNode pNew =(pNode)malloc(sizeof(struct Node));
	if(NULL == pNew)
	{
		printf("Assigning the ram space failed!");
		exit(-1);
	}

	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

	return;


}

void traverse_stack(S pS)
{
	pNode p = pS->pTop;

	while(p != pS->pBottom)
	{
		printf("%d ",p->data);
		p = p->pNext;
	} 
	printf("\n");
	return;
}


bool is_empty(S pS)
{
	if(pS->pBottom = pS->pTop)
		return true;	
	else
		return false;
}


bool pop_stack(S pS,int * val)
{
	if(is_empty(pS))
	{
		return false;
	}
	else
	{
		pNode r = pS->pTop;
		*val = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}
}


void clear_stack(S pS)
{
	if(is_empty(pS))
		return;
	else
	{
		pNode p = pS->pTop;
		pNode q = NULL;

		while(p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;

	}





}