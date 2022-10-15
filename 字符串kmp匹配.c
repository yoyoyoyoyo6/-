#include<stdio.h>
#include<stdlib.h>
typedef struct String
{
	char* data;  //数据域
	int len;	//存放字符串的长度
}String;

//初始化字符串
String* initString()
{
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;
}

//初始化的字符串中插入字符串
void stringAssing(String* s, char* data) {
	if (s->data) {
		free(s);
	}
	int len = 0;
	char* temp = data;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (len == 0) {
		s->data = NULL;
		s->len = 0;
	}
	else {
		temp = data;
		
		s->len = len;
		s->data = (char*)malloc(sizeof(char) + (len + 1));
		for (int i = 0; i < len; i++, temp++)
		{
			s->data[i] = *temp;
		}
	}
}
//实现next数组
// 实现原理：定义next[1] = 0; next数组的值由 匹配的最长前后缀+1 决定    到某个元素，就拿该元素前面的元素去找匹配的最长前后缀
//   如 a b c a b c  next[1] == 0;  next[2] == a不能和自己匹配=0 + 1 == 1  
//			 next[3] == 1  next[4] == 1  next[5] == 2  next[6] ==前面有ab前后缀相同 + 1 ==  3
//步骤1.创建两个变量作为指向要查找字符串和被查找字符串的查找定位
//2.算出next数组元素的值
// 通过例子解释代码
// 假设有一个字符串：s1 s2 s3 s4 s5 s6 s7 s8 s9 s10
// 状态1:假设s8的next数组的值为4，那么前缀的s1 s2 s3 就与后缀的 s5 s6 s7相配对，如果s4能继续与s8配对，则s9的next的值为5
// 状态2:承接上述的条件，但s4不能继续与s8配对，且s4的next数值为2，所以s1与s3配对，
//	又因为s1 s2 s3 与 s5 s6 s7相配对,所以s5与s7相配对，综上，可得s1 == s3 == s5 == s7
//		所以s7与s1配对，所以只要s2能与s8配对，s9的数值就为3
//   i就代表在要计算的元素的前一个元素，j代表细分的元素
// 在next数组中，i的数值是始终递增的
// next[++i] = ++j; 就代表上面s2与s8配对后，将s9的数值确定
//3.返回next数组
int* getNext(String* s) {
	int* next = (String*)malloc(sizeof(String) * s->len);
	if (next != NULL)
	{
		free(next);
	}
	int i = 1;
	int j = 0;
	next[i] = j;
	while (i <= s->len) {
		//
		if (j == 0 || s->data[i] == s->data[j]) {
			next[++i] = ++j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}


//实现kmp算法的查找
//核心：j = next[j]; 让查找的串跳过next[j]个元素，再次与被查找的串配对
void kmpMatch(String* master, String* sub, int* next) {
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len)
	{
		if (master->data[i] == sub->data[j]) {
			i++;
			j++;
		}
		else if (master->data[0] != sub->data[0])
		{
			i++;
		}
		else {
			//要跳多少个位
			j = next[j];
		}
	}
	if (j == sub->len) {
		printf("in\n");
	}
	else {
		printf("no\n");
	}
}

void printNext(int* next, int len) {
	for (int i = 1; i <= len; i++) {
		printf(i == 1 ? "%d" : "->%d", next[i]);
	}
	printf("\n");
}

void printString(String* s)
{
	for (int i = 0; i < s->len; i++)
	{
		printf(i == 0 ? "%c" : "->%c", s->data[i]);
	}
	printf("\n");
}



int main()
{
	String* a = initString();
	String* b = initString();
	stringAssing(a, "abcabc");
	stringAssing(b, "cab");
	printString(a);
	int* next = getNext(a);
	int* next1 = getNext(b);
	printNext(next1, b->len);
	printNext(next, a->len);
	kmpMatch(a, b, next1);
	
	return 0;
}
