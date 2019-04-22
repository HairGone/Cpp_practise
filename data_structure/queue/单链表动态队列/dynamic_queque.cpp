// 动态队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//带头节点的单链表

#include "pch.h"
#include <iostream>
#include "dynamic_queue.h"
void createQueue(queue*q)
{
	
	q->front=(node*)malloc(sizeof(node));
	q->front->next = NULL;
	q->rear = q->front;
}

int isEmpty(queue*q)
{
	return q->front == q->rear;
}
//int isFull(queue*q)
//{
//初始化中未定义队列的长度，随意无法判断size。而且这里的节点用链表形式，长度还没有限制。
//}

void insertQueue(queue*q, int ch)
{
	q->rear;
	q->rear->data;
	q->rear->next;

	node *pnode;
	pnode= (node*)malloc(sizeof(node));
	pnode->data = ch;

	pnode->next = q->rear->next;
	q->rear->next=pnode;
	q->rear = pnode;
	printf("入队数：%d\n", ch);

}

//
void deleteQueue(queue*q)
{
	if (q->rear==q->front->next) {
		q->front->next = q->front->next->next;
		free(q->rear);
			q->rear = q->front;
	}
	else {
		
		int ch = q->front->next->data;

		node *temp = q->front->next;
		q->front->next = q->front->next->next;
		free(temp);
	}

}

void tranverse(queue*q)
{
	if (q->front == q->rear)
		printf("队列为空，不能遍历\n");
	else
	{
		node *temp;
	//	temp = (node*)malloc(sizeof(node));
		temp= q->front->next;
		while (!(temp == q->rear->next))
		{
			printf("元素为：%d\n", temp->data);
			temp = temp->next;
			/*printf("元素为：%d\n", temp->data);
			temp = temp->next;
			temp = temp->next;
			printf("元素为：%d\n", temp->data);
			printf("元素为：%d\n", q->rear->data);
			printf("地址为：%d\n", temp);
			printf("地址为：%d\n", q->rear);*/

		}
		free(temp);
	}

}

void destoryQueue(queue*q)
{
	//free every node
	while (!(isEmpty(q)))
	{
		printf("删除元素是：%d\n", q->front->next->data);
		deleteQueue(q);
	}
}
//这里的clearup和我的destoryQUEUE功能一样。区别在于我的desotry是反复调用delete直至队列为空。clearup也类似，它创建了一个节点指针，用来循环删除队列中节点，直至指针为空。
//这里有一个疑问，当t->next之后指针是默认为空么，范围在那里？
//void clearQueue(struct Queue *q)
//{
//	struct QNode * t = q->front;
//	struct QNode * cur;
//	while (t)
//	{
//		cur = t->next;
//		free(t);
//		t = cur;
//	}q
//		->front = q->rear = NULL;
//}

int main()
{
	queue q;
	createQueue(&q);
	isEmpty(&q);
	insertQueue(&q, 1);
	insertQueue(&q, 2);
	insertQueue(&q, 3);
	insertQueue(&q, 4);
	/*tranverse(&q);
	deleteQueue(&q);
	deleteQueue(&q);*/
	tranverse(&q);
	destoryQueue(&q);
    //std::cout << "Hello World!\n"; 
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
