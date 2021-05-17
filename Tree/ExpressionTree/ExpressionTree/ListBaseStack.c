#include <stdio.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

void StackPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data StackPop(Stack* pstack)
{
	if (IsEmptyStack(pstack))
	{
		printf("Empty Stack ! \n");
		exit(-1);
	}

	Node* popNode;
	Data popData;

	popNode = pstack->head;
	popData = popNode->data;

	pstack->head = pstack->head->next;

	free(popNode);

	return popData;
}

int IsEmptyStack(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}