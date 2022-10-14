//1.初始化栈
//2.出栈
//3.入栈
//4.判断栈是否为空
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* initStack()
{
	Node* S = (Node*)malloc(sizeof(Node));
	S->data = 0;
	S->next = NULL;
	return S;
}

//判断栈是否为空
int isEmpty(Node* S)
{
	if (S->data == 0 || S->next == NULL)
	{
		return 1;
	}
	else
		return 0;
}

//获取栈中的元素
int getTop(Node* S)
{
	if (isEmpty(S))
	{
		return -1;
	}
	else
	{
		return S->next->data;
	}
}
//出栈
int pop(Node* S)
{
	if (isEmpty(S))
	{
		return -1;
	}
	else
	{
		Node* node = S->next;
		int data = node->data; 
		S->next = node->next;
		free(node);
		return data;
	}
}

//入栈
void push(Node* S, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = S->next;
	S->next = node;
	S->data++;
}

void printStack(Node* S)
{
	Node* node = S->next;
	while (node)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* l = initStack();
	push(l, 1);
	push(l, 2);
	int i = pop(l);
	printf("%d\n", i);
	printStack(l);
	return 0;
}
