/*1.初始化队列
2.入队
3.出队
4.遍历循环队列*/
/*1.牺牲队列一个空间，来去标识队列满or空
2.判断逻辑如下
rear为遍历时向后的指针，front为指向头的指针
队列为满：(rea+1)%MAXSIZE == front
队列为空: rear == front*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
typedef struct Node
{
	int data[MAXSIZE];
	int rear;
	int front;
}Node;

Node* initQueue()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->front = 0;
	node->rear = 0;
	return node;
}

int isFull(Node* node)
{
	if ((node->rear + 1) % MAXSIZE == node->front)
		return 1;
	else
		return 0;
}
int isEmpty(Node* node)
{
	if (node->rear == node->front)
	{
		return 1;
	}
	else
		return 0;
}
//入队
int enQueue(Node* node, int data)
{
	if (isFull(node))
	{
		return 0;
	}
	else
	{
		node->data[node->rear] = data;
		node->rear = (node->rear + 1) % MAXSIZE; //让rear的指向+1
		return 1;
	}
}
//出队
int deQueue(Node* node)
{
	if (isEmpty(node))
	{
		return -1;
	}
	else
	{
		//用data存放在node->data[node->front]上的元素
		int data = node->data[node->front];
		//让front的指向加1，原本存放在node->data[node->fornt]上的元素就不在队列中了
		node->front = (node->front + 1) % MAXSIZE;
		return data;
	}
}

void printQueue(Node* node)
{
	//要知道队列中有多少个元素
	//如果队尾减队首为正数，则该正数为队列中的元素个数
	//如果队尾减队首为负数，则要加上最大元素个数
	//所以综上，为了减少代码数，就将两者结合，
	//     (node->rear - node->front + MAXSIZE),但结果为正数时，又太大，所以要取模(结果为正数时取模就把加上的MAXSIZE去掉了)
	int length = (node->rear - node->front + MAXSIZE) % MAXSIZE;
	int index = node->front;
	for (int i = 0; i < length; i++)
	{
		printf("%d->", node->data[index]);
		//队列为一个循环，所以要index始终保持在MAXSIZE的范围中
		index = (index + 1) % MAXSIZE;
	}
	printf("NULL\n");
}

int main()
{
	Node* a = initQueue();
	enQueue(a, 1);
	enQueue(a, 2);
	enQueue(a, 3);
	int b = deQueue(a);
	printf("%d\n", b);
	printQueue(a);
	return 0;
}
