/*
The example of queue;
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct queue
{
	int * pBase;
	int front;
	int rear;
} queue_array;


void init_queue(queue_array * ,int );
bool en_queue(queue_array *,int,int);
bool del_queue(queue_array * ,int ,int *);
bool is_full_queue(queue_array * ,int);
bool is_empty_queue(queue_array *);
void traverse_queue(queue_array * ,int);




int main(void)
{
	int val = 0;
	int len = 6;
	queue_array aP;
	init_queue(&aP,len);
	en_queue(&aP,1,len);
	en_queue(&aP,2,len);
	en_queue(&aP,3,len);
	en_queue(&aP,4,len);
	en_queue(&aP,5,len);
	en_queue(&aP,6,len);
	en_queue(&aP,7,len);
	printf("%d\n",val);
	traverse_queue(&aP,len);

	return 0;
}


void init_queue(queue_array  * aP,int len)
{
	aP->pBase = (int *)malloc(sizeof(int)*len);
	aP->front = 0;
	aP->rear = 0;

	return;
}

bool is_full_queue(queue_array * aP,int len)
{
	if((aP->rear+1)%len == aP->front)
		return true;
	else
		return false;
}


bool en_queue(queue_array * aP,int val,int len)
{
	if (is_full_queue(aP,len))
	{
		return false;
	}
	else
	{
		aP->pBase[aP->rear] = val;
		aP->rear = (aP->rear+1) % len;

		return true;
	}
}


bool is_empty_queue(queue_array * aP)
{
	if(aP->front == aP->rear)
		return true;
	else
		return false;

}


bool del_queue(queue_array * aP,int len,int * pVal)
{
	if(is_empty_queue(aP))
	{
		return false;
	}
	else
	{

		*pVal = aP->pBase[aP->front];
		aP->front = (aP->front + 1) % len;
		return true;
	}
}


void traverse_queue(queue_array * aP,int len)
{
	int i = aP->front;

	while(i != aP->rear)
	{
		printf("%d\n",aP->pBase[i]);
		i = (i+1) % len;
	}

	return;

}







