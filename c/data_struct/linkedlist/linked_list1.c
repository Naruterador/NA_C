/*
Creating a nodes.
 */

#include <stdio.h>

typedef struct Node
{
	int data;               //data area;
	struct Node * pNext;    //pointer area;
} * NODE;




int main(void)
{
	NODE node1;
	NODE node2;
	
	node1->data = 1;
	node1->pNext = node2;

	node2->data = 2;
	node2->pNext = NULL;



	return 0;
}