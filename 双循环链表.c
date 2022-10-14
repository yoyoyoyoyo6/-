#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* pre;
}Node;
Node* initList()
{
	Node* headNode = (Node*)malloc(sizeof(Node));
	headNode->data = 0;
	headNode->next = headNode;
	headNode->pre = headNode;
	return headNode;
}

void headInsert(Node* headNode, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (headNode->data == 0)
	{
		//链表为空
		node->pre = headNode;
		node->next = headNode->next; //在没有插入node时，headNode->next的指向就为headNode->pre
		headNode->next = node;
		headNode->pre = node;
		headNode->data++;
	}
	else
	{
		node->next = headNode->next;
		node->pre = headNode;
		headNode->next = node;
		headNode->next->pre = node;
		headNode->data++;
	}
}
void Inesrt(Node* headNode, int data)
{
	Node* curNode = headNode->next;
	while (curNode) {
		if (curNode->data == data) {
			//删除节点 
			if (curNode->next != NULL) {
				//不是最后一个节点
				curNode->pre->next = curNode->next;
				curNode->next->pre = curNode->pre;
				free(curNode);
				headNode->data--;
			}
			else {
				//最后一个节点
				curNode->pre->next = NULL;
				free(curNode);
				headNode->data--;
			}
			return TRUE;

		}
		curNode = curNode->next;
	}
	return FALSE;
}

void tailInsert(Node* headNode, int data)
{
	Node* node = headNode;
	while (node->next != headNode)
	{
		node = node->next;
	}
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->pre =  node;
	n->next = headNode;
	headNode->pre = n;
	node->next = n;
	headNode->data++;
}



void printNode(Node* headNode)
{
	Node* head = headNode->next;
	while (head->next != headNode)
	{
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}


int main()
{
	Node* l = initList();
	headInsert(l, 1);
	headInsert(l, 2);
	headInsert(l, 3);
	tailInsert(l, 4);
	printNode(l);
	return 0;
}
