#include <stdio.h>
int BSearchRecur(int arr[], int first, int last, int target)
{
	int mid;

	if (first > last)
		return -1;
	mid = (first + last) / 2;
	
	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		BSearchRecur(arr, first, mid - 1, target);
	else
		BSearchRecur(arr, mid + 1, last, target);
	
}

int main(vod)
{
	int arr[] = { 1,3,5,7 };
	int idx;
	
	idx = BSearchRecur(arr,0,sizeof(arr)/sizeof(int)-1,4);
	if (idx == -1)
		printf("Ž�� ����\n");

	else
		printf("Ÿ�� ���� �ε���\n", idx);
	
	return 0;
}