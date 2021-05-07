#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQisEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head;
	if (DQisEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (DQisEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	if (DQisEmpty(pdeq))
	{
		printf("Deque is Empty\n");
		exit(-1);
	}

	Node* delNode = pdeq->head;
	Data delData = pdeq->head->data;

	pdeq->head = pdeq->head->next;
	free(delNode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return delData;
}

Data DQRemoveLast(Deque* pdeq)
{
	if (DQisEmpty(pdeq))
	{
		printf("Deque is Empty\n");
		exit(-1);
	}

	Node* delNode = pdeq->tail;
	Data delData = pdeq->tail->data;

	pdeq->tail = pdeq->tail->prev;
	free(delNode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return delData;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQisEmpty(pdeq))
	{
		printf("Deque is Empty\n");
		exit(-1);
	}
	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
	if (DQisEmpty(pdeq))
	{
		printf("Deque is Empty\n");
		exit(-1);
	}
	return pdeq->tail->data;
}