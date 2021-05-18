#include <stdio.h>
#include <string.h>
#include "Heap.h"
int DataPriorityComp(char *ch1, char *ch2)
{
	return strlen(ch2) - strlen(ch1);
}
int main(void)
{
	Heap myheap;
	HeapInit(&myheap,DataPriorityComp);
	HInsert(&myheap, "1");
	HInsert(&myheap, "12");
	HInsert(&myheap, "123");
	HInsert(&myheap, "1234");
	HInsert(&myheap, "5");

	while (!HIsEmpty(&myheap))
	{		
		printf("Á¦°ÅµÈ ³ð : %s \n", HDelete(&myheap));
	}

	return 0;
}