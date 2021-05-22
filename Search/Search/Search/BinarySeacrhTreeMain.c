#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode* bstRoot;
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);
	BSTInsertData(&bstRoot, 9);
	BSTInsertData(&bstRoot, 1);
	BSTInsertData(&bstRoot, 6);
	BSTInsertData(&bstRoot, 2);
	BSTInsertData(&bstRoot, 8);
	BSTInsertData(&bstRoot, 3);
	BSTInsertData(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ Ű �� : %d\n", GetData(sNode));
	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ Ű �� : %d\n", GetData(sNode));
	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ Ű �� : %d\n", GetData(sNode));
	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("Ž�� ����\n");
	else
		printf("Ž���� ������ Ű �� : %d\n", GetData(sNode));
}