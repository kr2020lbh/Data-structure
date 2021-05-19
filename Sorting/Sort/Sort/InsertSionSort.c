#include <stdio.h>

void InsertSort(int arr[], int n)
{
	int i, j;
	int insData;
	for (i = 1; i < n; i++) {
		insData = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (insData < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}
/*
int main(void)
{
	int arr[5] = { 5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(int);
	InsertSort(arr, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
*/