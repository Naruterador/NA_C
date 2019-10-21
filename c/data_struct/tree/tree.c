/*
A example of binary tree that creates statically;
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
} * Node;


Node Create_BTree(void);
void PreorderTraversalBTree(Node);
void InorderTraversalBTree(Node);
void PostorderTraversalBTree(Node);




int main(void)
{

	Node PT = Create_BTree();
	//PreorderTraversalBTree(PT);
	//InorderTraversalBTree(PT);
	PostorderTraversalBTree(PT);
	return 0;
}

Node Create_BTree(void)
{

	Node PA = (Node)malloc(sizeof(struct BTNode));
	Node PB = (Node)malloc(sizeof(struct BTNode));
	Node PC = (Node)malloc(sizeof(struct BTNode));
	Node PD = (Node)malloc(sizeof(struct BTNode));
	Node PE = (Node)malloc(sizeof(struct BTNode));

	PA->data = 'A';
	PA->pLchild = PB;
	PA->pRchild = PC;

	PB->data = 'B';
	PB->pLchild = NULL;
	PB->pRchild = NULL;

	PC->data = 'C';
	PC->pLchild = PD;
	PC->pRchild = NULL;

	PD->data = 'D';
	PD->pLchild = NULL;
	PD->pRchild = PE;

	PE->data = 'E';
	PE->pLchild = NULL;
	PE->pRchild = NULL;

	return PA;

}

void PreorderTraversalBTree(Node PT)
{
	if (NULL != PT)
	{
		printf("%c\n",PT->data);

		if(NULL != PT->pLchild)
			PreorderTraversalBTree(PT->pLchild);
		if(NULL != PT->pRchild)
			PreorderTraversalBTree(PT->pRchild);

	}

}


void InorderTraversalBTree(Node PT)
{
	if (NULL != PT)
	{
		if(NULL != PT->pLchild)
			InorderTraversalBTree(PT->pLchild);

		printf("%c\n",PT->data);

		if(NULL != PT->pRchild)
			InorderTraversalBTree(PT->pRchild);

	}
}


void PostorderTraversalBTree(Node PT)
{

	if (NULL != PT)
	{
		if(NULL != PT->pLchild)
			PostorderTraversalBTree(PT->pLchild);

		if(NULL != PT->pRchild)
			PostorderTraversalBTree(PT->pRchild);

		printf("%c\n",PT->data);

	}

}