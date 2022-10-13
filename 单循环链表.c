#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* initList()
{
	Node* headNode = (Node*)malloc(sizeof(struct Node));
	headNode->data = 0;
	headNode->next = headNode;
	return headNode;
}
//头插法
void headInsert(Node* headNode, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = headNode->next;
	headNode->next = node;
	headNode->data++;
}

void tailInsert(Node* headNode, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node* head = headNode;
	while (head->next != headNode)
	{
		head = head->next;
	}
	node->next = headNode;
	head->next = node;
}

int delete(Node* headNode, int data)
{
	Node* node = headNode->next;
	Node* currst = headNode;

	while (node != headNode)
	{
		if (node->data == data)
		{
			currst->next = node->next;
			free(node);
			return TRUE;
		}
		currst = currst->next;
		node = node->next;
	}
	return FALSE;
}

void printNode(Node* headNode)
{
	Node* node = headNode->next;
	while (node != headNode)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
int main()
{
	Node* l = initList();
	headInsert(l, 1);
	headInsert(l, 2);
	headInsert(l, 3);
	headInsert(l, 4);
	tailInsert(l, 5);
	tailInsert(l, 6);
	delete(l, 4);
	delete(l, 5);
	printNode(l);
	return 0;
}
