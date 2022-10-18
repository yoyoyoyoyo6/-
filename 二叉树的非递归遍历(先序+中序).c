#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//定义一个栈
typedef struct StackNode
{
	TreeNode* data;
	struct StackNode* next;
}StackNode;


//创建一个二叉树
TreeNode* createBiTree()
{
	int a = 0;
	TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
	scanf_s("%d", &a);
	if (a == 0)
	{
		T = NULL;
	}
	else
	{
		T->data = a;
		T->lchild = createBiTree();
		T->rchild = createBiTree();
	}
	return T;
}

//创建一个栈
StackNode* initStack()
{
	StackNode* S = (StackNode*)malloc(sizeof(StackNode));
	S->data = NULL;
	S->next = NULL;
	return S;
}

//入栈
void push(TreeNode* data, StackNode* S)
{
	//头插法在栈中插入元素 插入node->data = data;
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->data = data;
	node->next = S->next;
	S->next = node;
}

//判断栈是否为空
int isEmpty(StackNode* S)
{
	if (S->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//出栈
StackNode* pop(StackNode* S)
{
	if (isEmpty(S))
	{
		return NULL;
	}
	else
	{
		//把S给出栈了
		StackNode* node = S->next;
		S->next = node->next;
		return node;
	}
}

//非递归的遍历
//步骤
//1.根节点入栈
//2.循环，直到左孩子为空
//3.左孩子为空时，出栈，访问节点，入栈右孩子
void preOrder(TreeNode* T)
{
	TreeNode* node = T;
	StackNode* S = initStack();
	while (node || !isEmpty(S))
	{
		if (node)
		{
			printf("%d ", node->data);
			push(node, S);
			node = node->lchild;
		}
		else
		{
			node = pop(S)->data;
			node = node->rchild;
		}
	}
}

int main()
{
	TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
	T = createBiTree();
	preOrder(T);
	return 0;
}
