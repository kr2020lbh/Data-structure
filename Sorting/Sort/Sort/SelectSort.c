#include <stdio.h>

void SelSort(int arr[], int n)
{
    int i, j;
    int temp;
    int idx;

    for (i = 0; i < n; i++)
    {
        idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[idx] > arr[j])
                idx = j;
        }
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}
/*
int main(void)
{
   int arr[5] = { 5,4,3,1,1 };
   SelSort(arr, sizeof(arr) / sizeof(int));

   for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
   {
      printf("%d ", arr[i]);
   }
}
*/