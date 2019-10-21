/*
Creating a linked list and traversing it;
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
} * pNode;



pNode create_list(void);
void traverse(pNode);
bool is_empty(pNode);
int length_list(pNode);
bool insert_list(pNode,int,int);
bool delete_list(pNode,int,int *);
void sort_list(pNode);




int main(void)
{
	int val;
	pNode pHead = NULL;

	pHead = create_list();

	delete_list(pHead,3,&val);
	

	printf("\n\n\n\n\n");
	printf("%d\n",val);
	
	//insert	_list(pHead,1,100);
	traverse(pHead);

	return 0;
}

pNode create_list(void)
{
	int len;  //The length of linked list;
	int i;
	int val;

	printf("Please input the length of the linked list:\n");
	scanf("%d",&len);

	pNode pHead =(pNode)malloc(sizeof(struct Node));     //Creating a head node;
	
	if(pHead == NULL)
	{
		printf("Assigning the ram space failed!");
		exit(-1);
	}
	
	pNode pTail = pHead;                                //Creating a tail node;
	pTail->pNext = NULL;                                //If the user inputting zero;


	for(i = 0;i < len;i++)
	{
		printf("Please input the %d value of linked list:\n",i+1);
		scanf("%d",&val);

		pNode pNew = (pNode)malloc(sizeof(struct Node));          //Creaing the elements of linked list by loop;
		if(pNew == NULL)
		{
			printf("Assigning the ram space failed!");
			exit(-1);
		}

		pNew->data = val;
		pTail->pNext = pNew; //Setting the next element pointer for previous node;
		pNew->pNext = NULL;  //Seting the pointer of tail node as NULL;
		pTail = pNew;

	}

	return pHead;            //return the pointer of head node;
}

void traverse(pNode pHead)
{
	pNode p = pHead->pNext;

	while(NULL != p)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

bool is_empty(pNode pHead)
{
	if(pHead->pNext == NULL)
		return true;
	else
		return false;
}

int length_list(pNode pHead)
{
	int len = 0;
	pNode p = pHead->pNext;

	while(NULL != p)
	{
		len++;
		p = p->pNext;
	}
	return len;
}


void sort_list(pNode pHead)
{
	int i,j,t;
	pNode p,q;

	int len = length_list(pHead);

	for(i = 0,p = pHead->pNext;i < len - 1;i++,p = p->pNext)
		for(j = i+1,q = p->pNext;j < len;j++,q = q->pNext)
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
	return;

}

bool insert_list(pNode pHead,int position,int val)
{
	int i = 0;
	pNode p = pHead->pNext;
	while(NULL != p && i < position - 1)
	{
		p = p->pNext;
		i++;
	}

	if(NULL == p || i > position - 1)
		return false;

	pNode pNew = (pNode)malloc(sizeof(struct Node));

	pNew->data = val;

	pNode q;
	q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	 return true;
}

bool delete_list(pNode pHead,int position,int * val)
{
	int i = 0;
	pNode p = pHead;
	while(NULL != p->pNext && i < position - 1)
	{
		p = p->pNext;
		i++;
	}

	if(NULL == p->pNext || i > position - 1)
		return false;

	pNode q;
	pNode r = p;
	q = p->pNext;
	*val = q->data;

	r->pNext = p->pNext->pNext;

	free(q);
	q = NULL;

	return true;
}