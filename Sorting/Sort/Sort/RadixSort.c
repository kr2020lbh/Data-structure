#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen)
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int radix;
	int divFac = 1;
	int i;

	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	for (int pos = 0; pos < maxLen; pos++)
	{
		for (i = 0; i < num; i++)
		{
			radix = (arr[i] / divFac) % 10;
			Enqueue(&buckets[radix], arr[i]);
		}
		
		for (bi = 0, i = 0; bi < BUCKET_NUM; bi++)
		{
			while (!QIsEmpty(&buckets[bi]))
				arr[i++] = Dequeue(&buckets[bi]);
		}

		divFac *= 10;
	}
}


/*
int main(void)
{
	int arr[7] = { 13,421,215,643,123,756,9 };
	int n = sizeof(arr) / sizeof(int);

	RadixSort(arr, n, 3);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;

}
*/