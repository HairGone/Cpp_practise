#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct Queue {
	char * _space;
	int _rear;
	int _front;
	int _len;
} queue;

extern int createQueue(queue *q, int len);
extern int isEmpty(queue *q);
extern int isFull(queue *q);
extern int insert(queue *q,char ch);
extern int delet(queue *q);
extern void tranverse(Queue *q);
extern void clearup(queue *q);
extern void destory(queue *q);
extern int size(queue *q);





#endif // !_QUEUE_H_
