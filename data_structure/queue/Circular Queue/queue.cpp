// 队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//静态队列，参考王桂林老师的c/c++数据结构，个人学习使用
//遍历等几个函数是我自己写的。马丹，加油！

#include "pch.h"
#include <iostream>
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>



//extern void tranverse();
//extern void clearup();
//extern int destory();
//extern int size();

void tranverse(Queue *q)
{
	int temp;
	temp = q->_front;
	printf("队列遍历");
	while (!(temp == q->_rear))
	{
		printf("队列 %d 元素为%c\n",temp,q->_space[temp]);
		temp++;
	}
}

void clearup(queue *q)
{
	q->_front = q->_rear = 0;
	q->_space = NULL;
}
void destory(queue *q)
{
	free(q->_space);
	(q->_space = NULL) ? printf("desotry\n") : printf("desotry failed!\n");
}

int size(queue *q)
{
	printf("size is %d\n", q->_len);
	return q->_len;
};
int createQueue(queue *q,int len)
{
	q->_front = q->_rear = 0;
	q->_space = (char*)malloc(sizeof(char)*len);
	q->_len = len;
	printf("创建链表\n");
	return 1;
}

int isFull(queue *q)
{
	return (q->_rear + 1) % q->_len == q->_front;

}
int isEmpty(queue *q) {
	return q->_rear== q->_front;

}

int insert(queue *q, char ch)
{
	int j = isFull(q);
	if (j == 1) 
	{ printf("队列满,不能输入\n"); return 0; }
	else printf("队列不满\n");
	q->_space[q->_rear ] = ch;
	q->_rear = (q->_rear + 1) % q->_len;
	printf("输入成功\n");
	return 1;
}
int delet(queue *q)
{
	char ch = q->_space[q->_front];
	q->_front = (q->_front + 1) % q->_len;
	return ch;
}

int main()
{
	queue q;
	createQueue(&q,5);
	int i=isEmpty(&q);
	if (i == 1) printf("队列为空\n"); else printf("队列不为空\n");

	
	insert(&q,'a');
	i = isEmpty(&q);
	if (i == 1) printf("队列为空\n"); else printf("队列不为空\n");

	insert(&q, 'b');

	insert(&q, 'c');
	insert(&q, 'd');

	insert(&q, 'e');
	insert(&q, 'f');
	

	tranverse(&q);
	size(&q);
	delet(&q);
	tranverse(&q);
	clearup(&q);
	tranverse(&q);
	return 0;
}
