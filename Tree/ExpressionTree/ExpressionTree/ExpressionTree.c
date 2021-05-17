#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int explen = strlen(exp);
	int i;
	StackInit(&stack);

	for (i = 0; i < explen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, StackPop(&stack));
			MakeLeftSubTree(pnode, StackPop(&stack));
			SetData(pnode, exp[i]);
		}

		StackPush(&stack, pnode);
	}
	return StackPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '/':
		return op1 / op2;
	case '*':
		return op1 * op2;
	}

	return 0;
}

void ShowBTreeNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowBTreeNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	if (bt->left != NULL && bt->right != NULL)
		printf("( ");
	ShowInfixTypeExp(bt->left);
	ShowBTreeNodeData(bt->data);
	ShowInfixTypeExp(bt->right);
	if (bt->left != NULL && bt->right != NULL)
		printf(") ");

}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowBTreeNodeData);
}