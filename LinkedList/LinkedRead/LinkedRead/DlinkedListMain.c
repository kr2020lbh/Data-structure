#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}
int main(void)
{
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22);

	if (LFirst(&list, &data))
	{
		printf("%d\n", data);
		while (LNext(&list, &data))
		{
			printf("%d\n", data);
		}
	}
	return 0;
}