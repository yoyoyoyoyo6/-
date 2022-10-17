#include<stdio.h>
#include<stdlib.h>

//定义一个二叉树
typedef struct TreeNode
{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//定义一个队列
typedef struct QueueNode
{
	TreeNode* data;
	struct QueueNode* pre;
	struct QueueNode* next;
}QueueNode;

//新建一个二叉树
TreeNode* createBiTree()
{
	int a;
	TreeNode* T;
	scanf_s("%d", &a);
	if (a == 0)
	{
		T = NULL;
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->data = a;
		T->lchild = createBiTree();
		T->rchild = createBiTree();
	}
	return T;
}

//前序遍历二叉树
void printTree(TreeNode* T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		printTree(T->lchild);
		printTree(T->rchild);
	}
}

//中序遍历二叉树
void printTree1(TreeNode* T)
{
  	if (T != NULL)
	{
		printTree1(T->lchild);
    printf("%d ", T->data);
		printTree1(T->rchild);
	}
}

//后序遍历二叉树
void printTree2(TreeNode* T)
{ 
   if (T != NULL)
	{
		printTree2(T->lchild);
		printTree2(T->rchild);
    printf("%d ", T->data);
	}
}


//新建队列
QueueNode* initQueue()
{
	QueueNode* Q = (QueueNode*)malloc(sizeof(QueueNode));
	Q->data = NULL;
	Q->next = Q;
	Q->pre = Q;
	return Q;
}

//判断队列是否为空
int isEmpty(QueueNode* Q)
{
	if (Q->next == Q)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//删除队列元素->出队
//和leveTravers函数搭配使用
QueueNode* deQueue(QueueNode* Q)
{
	if (isEmpty(Q))
	{
		return NULL;
	}
	else
	{
		QueueNode* node = Q->next;
		Q->next->next->pre = Q;
		Q->next = Q->next->next;
		return node;
	}
}

//尾部插入元素->TreeNode* data
void enQueue(TreeNode* data, QueueNode* Q)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = data;
	node->next = Q;
	node->pre = Q;
	Q->pre->next = node;
	Q->pre = node;
}

//层次遍历二叉树
void levelTravers(QueueNode* Q, TreeNode* T)
{
	enQueue(T, Q);
	while (!isEmpty(Q))
	{
		//出队+打印
		QueueNode* node = deQueue(Q);
		printf("%d ", node->data->data);
		//左不为空，插入左孩子
		if (node->data->lchild)
		{
			enQueue(node->data->lchild, Q);
		}
		//右不为空，插入右孩子
		if (node->data->rchild)
		{
			enQueue(node->data->rchild, Q);
		}
	}
}



int main()
{
	TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
	T = createBiTree();
	QueueNode* Q = (QueueNode*)malloc(sizeof(QueueNode));
	Q = initQueue();
	//enQueue(Q, T);
	//levelTravers(Q, T);
	printTree(T);
	printf("\n");
	levelTravers(Q, T);
	printf("\n");
	return 0;
}
