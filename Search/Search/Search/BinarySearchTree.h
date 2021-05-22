#pragma once

typedef int BSTData;

typedef struct _bTreeNode
{
	BSTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTreeNode* BSTMakeAndInit(BTreeNode** pRoot);
BSTData GetData(BTreeNode* bst);

void BSTInsertData(BTreeNode** pRoot, BSTData data);
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void BSTShowAll(BTreeNode* bst);

BTreeNode* GetLeftSubTree(BTreeNode* bst);
BTreeNode* GetRightSubTree(BTreeNode* bst);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);


