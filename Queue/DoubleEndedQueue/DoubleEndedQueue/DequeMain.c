#include <stdio.h>
#include "Deque.h"

int main(void)
{
	Deque deq;
	DequeInit(&deq);

	DQAddFirst(&deq, 31);
	DQAddFirst(&deq, 52);
	DQAddLast(&deq, 1);
	DQAddLast(&deq, 0);
	printf("DQRemoveFirst\n");
	while (!DQisEmpty(&deq))
	{
		printf("%d ", DQRemoveFirst(&deq));
	}
	printf("\n");
	printf("DQRemoveLasst\n");
	DQAddFirst(&deq, 31);
	DQAddFirst(&deq, 52);
	DQAddLast(&deq, 1);
	DQAddLast(&deq, 0);

	while (!DQisEmpty(&deq))
	{
		printf("%d ", DQRemoveLast(&deq));
	}
	return 0;
}
