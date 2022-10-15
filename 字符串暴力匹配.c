//1.初始化字串
//2，暴力匹配
#include<stdio.h>
#include<stdlib.h>

typedef struct String
{
	char* data;  //数据域
	int len;   //存放字符串长度
}String;

//创建一个字符串or 初始化字符串
String* initString()
{
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;
}


//在初始化后的字符串中插入元素
//步骤1.计算字符串长度
//2.让动态创建的字符串存储输入的字符串
void stringAssign(String* s, char* data)
{
	//如果有s->data中有内容，就free掉，防止产生野指针
	if (s->data) 
	{
		free(s);
	}
	int len = 0;
	char* tmp = data;
	//计算字符串长度len
	while (*tmp)
	{
		len++;
		tmp++;
	}
	if (len == 0) {
		s->data = NULL;
		s->len = 0;
	}
	else {
		tmp = data;
		s->len = len;
		// 字符串中有'\0'，所以开辟s->data空间时len(计算len时无包含'\0')要加上1
		s->data = (char*)malloc(sizeof(char) * (len + 1));
		for (int i = 0; i < len; i++ , tmp++)
		{
			s->data[i] = *tmp;
		}
	}
}

//暴力匹配
//步骤1.定义两个变量，作为被查找字符串和要查找的字符串中元素的指针
//2.如果要查找的字符串中的元素和被查找字符串中的元素相等，那就将俩个指针自增1，
//     如果不相等，则让被查找字符串从前一次开始遍历的元素的下一个元素开始向下查找，要查找的字符串则从头开始查找
//3.如果指向要查找的字符串的指针等于要查找的字符串的长度，那么就说明要查找的字符串为被查找字符串的子串
void forceMatch(String* master, String* sub)
{
	int i = 0;
	int j = 0;
	//
	while (i < master->len && j < sub->len) {
		//如果master->data[i] == sub->data[j]时，说明匹配上了，就让i，j都++.继续向下查找
		if (master->data[i] == sub->data[j]) {
			i++; 
			j++;
		}
		//else 从头开始再次遍历
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	//j与sub->len相等时，说明子串已经遍历完了，查找介绍
	if (j == sub->len) {
		printf("ok\n");
	}
	else {
		printf("no\n");
	}
}

void printSting(String* s)
{
	for (int i = 0; i < s->len; i++)
	{
		printf(i == 0 ? " %c " : "-> %c", s->data[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	String* a = initString();
	String* b = initString();
	stringAssign(a, "hello");
	printSting(a);
	stringAssign(b, "llo");
	printSting(b);
	forceMatch(a, b);
	
	return 0;
}
