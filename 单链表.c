// 动态创建一个链表： 动态内存申请+模块化设计
//1.创建链表（创建一个表头表示整个链表）
//2.创建节点
//3.插入节点
//4.删除节点
//5.打印遍历链表（测试）


#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;       //数据域
	struct Node* next;   // 指针域
}Node;
struct Node* createList()  //创造一个表头表示整个链表  创造不同的头节点，分散无联系
{
	struct Node* handNode = (struct Node*)malloc(sizeof(struct Node));//设置一个headNode表示表头的信息，动态内存分配给一个struct Node大小的空间
	//将头节点的next指针指向空
	handNode->data = 0;
	handNode->next = NULL;
	return handNode;
}
void headInsert(Node* handNode, int data)  // 头插法  //data是我要插入的数
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = handNode->next;
	handNode->next = node;  // 把头节点用头插的元素代替
	handNode->data++; // 让头节点存储链表中有几个元素
}

void tailInsert(Node* handNode, int data)
{
	Node* head = handNode;
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
	handNode = handNode->next; //让指针先指向头节点
	while (handNode->next)
	{
		handNode = handNode->next;
	} // 跳出循环时handNode的next是最后一个节点
	handNode->next = node;
	head->data++;
}
void delete(Node* handNode, int data)
{
	Node* head = handNode;
	//保存当前编列的节点
	Node* current = handNode->next;
	//保存遍历节点前一个节点
	Node* pre = handNode;
	while (current)
	{
		if (current->data == data)
		{
			pre->next = current->next;  //pre跟着保存当前遍历的节点的下一个节点
			free(current);
			break;
		}
		else
		{
			pre = current;
			current = current->next;
		}
	}
	handNode->data--;
}

void printNode(Node* handNode)
{
	handNode = handNode->next;
	while (handNode)
	{
		printf("%d ", handNode->data);
		handNode = handNode->next;
	}
	printf("\n");
}
int main()
{
	Node* list = createList();
	headInsert(list, 1);
	headInsert(list, 2);
	headInsert(list, 3);
	headInsert(list, 4);
	headInsert(list, 5);
	headInsert(list, 6);
	delete(list, 4);
	delete(list, 1);
	delete(list, 6);
	printNode(list);
	system("pause");
	return 0;
}
