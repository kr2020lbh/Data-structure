/*#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1)
	{
		printf("자연수 입력 : ");
		scanf_s("%d", &readData);
		if (readData < 1) break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		newNode->next = head;
		head = newNode;
	}

	printf("입력 받은 데이터의 출력\n");
	if (head == NULL)
		printf("입력 받은 데이터가 없다.\n");
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("%d를 삭제합니다.\n", delNode->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNode->next;
			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}*/