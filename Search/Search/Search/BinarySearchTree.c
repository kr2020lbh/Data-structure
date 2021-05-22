#include <stdio.h>
#include "BinarySearchTree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
BTreeNode* BSTMakeAndInit(BTreeNode **pRoot)
{
	*pRoot = NULL;
}

BSTData GetData(BTreeNode* bst)
{
	return bst->data;
}

void BSTInsertData(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* parentNode = NULL;
	BTreeNode* currentNode = *pRoot;
	BTreeNode* newNode = NULL;

	while (currentNode != NULL)
	{
		if (data == GetData(currentNode))
			return;
		parentNode = currentNode;
		if (GetData(currentNode) > data)
			currentNode = GetLeftSubTree(currentNode);
		else
			currentNode = GetRightSubTree(currentNode);
	}

	newNode = MakeBTreeNode();
	newNode->data = data;

	if (parentNode != NULL)
	{
		if (GetData(parentNode) > data)
			MakeLeftSubTree(parentNode, newNode);
		else
			MakeRightSubTree(parentNode, newNode);
	}
	else
	{
		*pRoot = newNode;
	}

}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* currentNode = bst;
	BSTData currentData;

	while (currentNode != NULL)
	{
		currentData = GetData(currentNode);
		if (target == currentData)
			return currentNode;
		else if (target < currentData)
			currentNode = GetLeftSubTree(currentNode);
		else
			currentNode = GetRightSubTree(currentNode);
	}
	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pvRoot = MakeBTreeNode();
	BTreeNode* parentNode = pvRoot;
	BTreeNode* currentNode = *pRoot;
	BTreeNode* delNode;

	ChangeRightSubTree(pvRoot, *pRoot);

	while (currentNode != NULL && GetData(currentNode) != target)
	{
		parentNode = currentNode;
		if (target < GetData(currentNode))
			currentNode = GetLeftSubTree(currentNode);
		else
			currentNode = GetRightSubTree(currentNode);
	}

	if (currentNode == NULL)
		return NULL;

	delNode = currentNode;

	if (GetLeftSubTree(delNode) == NULL && GetRightSubTree(delNode) == NULL)
	{
		if (GetLeftSubTree(parentNode) == delNode)
			RemoveLeftSubTree(parentNode);
		else
			RemoveRightSubTree(parentNode);
	}

	else if (GetLeftSubTree(delNode) == NULL || GetRightSubTree(delNode) == NULL)
	{
		BTreeNode* delChildNode;

		if (GetLeftSubTree(delNode) != NULL)
			delChildNode = GetLeftSubTree(delNode);
		else
			delChildNode = GetRightSubTree(delNode);

		if (GetLeftSubTree(parentNode) == delNode)
			ChangeLeftSubTree(parentNode, delChildNode);
		else
			ChangeRightSubTree(parentNode, delChildNode);
	}

	else
	{
		BTreeNode* mNode = GetRightSubTree(delNode);
		BTreeNode* mpNode = GetRightSubTree(delNode);
		int delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(delNode);
		delNode->data = mNode->data;

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		delNode = mNode;
		delNode->data = delData;
	}

	if (GetRightSubTree(pvRoot) != *pRoot)
		*pRoot = GetRightSubTree(pvRoot);

	free(pvRoot);
	return delNode;
}

BTreeNode* GetLeftSubTree(BTreeNode* bst)
{
	return bst->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bst)
{
	return bst->right;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;
	if (bt != NULL)
	{
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;
	if (bt != NULL)
	{
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}