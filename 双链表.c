/*1.初始化链表
2.插入节点（头插，尾插）
3.删除节点
4.遍历链表*/
#define TRUE 1
#define FALSE 0

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* initList()
{
	Node* headNode = (Node*)malloc(sizeof(Node));
	headNode->data = 0;
	headNode->next = NULL;
	headNode->pre = NULL;
	return headNode;
}

void headInsert(Node* headNode, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (headNode->data == 0)
	{
		//链表为空
		node->next = headNode->next;
		node->pre = headNode;
		headNode->next = node;
		headNode->data++;
	}
	else {
		node->pre = headNode;
		node->next = headNode->next;
		headNode->next->pre = node;
		headNode->next = node;
		headNode->data++;
	}
	
}

void tailInsert(Node* headNode, int data)
{
	Node* node = headNode;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	while (node->next)
	{
		node = node->next;
	}
	n->next = node->next;
	node->next = n;
	n->pre = node;
	headNode->data++;
}

int delete(Node* headNode, int data)
{
	Node* node = headNode->next;
	Node* n = headNode->next;
	while (node)
	{
		if (node->data == data)
		{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			return TRUE;
		}
		node = node->next;
	}
	return FALSE;
}

void printNode(Node* headNode)
{
	Node* node = headNode;
	while (node->next)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* a = initList();
	headInsert(a, 1);
	headInsert(a, 2);
	headInsert(a, 3);
	headInsert(a, 4);
	headInsert(a, 7);
	tailInsert(a, 5);
	tailInsert(a, 6);
	delete(a, 3);
	printNode(a);
	return 0;
}
