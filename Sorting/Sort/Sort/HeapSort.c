#include <stdio.h>
#include "Heap.h"

int AscendingOrder(int n1, int n2)
{
	return n2 - n1;
}

int DescendingOrder(int n1, int n2)
{
	return n1 - n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;
	HeapInit(&heap, pc);

	for (i = 0; i < n; i++)
	{
		HInsert(&heap, arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = HDelete(&heap);
	}
}

/*
int main(void)
{
	int arr[6] = { 1,6,34,32,12,4 };
	int n = sizeof(arr) / sizeof(int);

	HeapSort(arr, n, AscendingOrder);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, n, DescendingOrder);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
*/