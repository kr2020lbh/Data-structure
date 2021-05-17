#include <stdio.h>
#include "ExpressionTree.h"
int main(void)
{
	char exp[] = "32-7+2*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("PreFix \n");
	ShowPrefixTypeExp(eTree); printf("\n");
	printf("InFix \n");
	ShowInfixTypeExp(eTree); printf("\n");
	printf("PostFix \n");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("°á°ú : %d ", EvaluateExpTree(eTree));
	return 0;
}