#pragma
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack
{
	Node* head;
} listStack;

typedef listStack Stack;

void StackInit(Stack* pstack);
void StackPush(Stack* pstack, Data data);
Data StackPop(Stack* pstack);
int IsEmptyStack(Stack* pstack);

