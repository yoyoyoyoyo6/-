//1.初始化队
//2.出队
//3.入队
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* initQueue()
{
	Node* Q = (Node*)malloc(sizeof(Node));
	Q->data = 0;
	Q->next = NULL;
	return Q;
}

void enQueue(Node* Q, int data)
{
	Node* q = Q;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (q->next)
	{
		q = q->next;
	}
	node->next = q->next;
	q->next = node;
	Q->data++;
}

int isEmpty(Node* Q)
{
	if (Q->data == 0 || Q->next == NULL)
	{
		return 1;
	}
	else
		return 0;
}

int deQueue(Node* Q)
{
	if (isEmpty(Q))
	{
		return -1;
	}
	else
	{
		Node* node = Q->next;
		int data = node->data;
		Q->next = node->next;
		free(node);
		Q->data--;
		return data;
	}
	
}

void printQueue(Node* Q)
{
	Node* node = Q->next;
	while (node)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* Q = initQueue();
	enQueue(Q, 1);
	enQueue(Q, 1);
	enQueue(Q, 1);
	printQueue(Q);
	int i = deQueue(Q);
	printf("%d\n", i);
	printQueue(Q);
	return 0;
}
