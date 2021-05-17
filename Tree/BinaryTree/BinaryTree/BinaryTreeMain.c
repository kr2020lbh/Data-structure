#include <stdio.h>
#include "BinaryTree.h"


void ShowIntData(int data)
{
	printf("%d ", data);
}

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeRightSubTree(bt2, bt4);

	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n"); 
	PostorderTraverse(bt1, ShowIntData);


	return 0;
}
