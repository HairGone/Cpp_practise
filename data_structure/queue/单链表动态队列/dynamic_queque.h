#pragma once
#ifndef _DYNAMIC_QUEUE_H_
#define _DYNAMIC_QUEUE_H_


typedef struct Qnode
{
	int data;
	struct Qnode * next;
} node;

typedef struct Pnode
{
	struct Qnode *front, *rear;
} queue;


extern void createQueue(queue* q);
extern void destoryQueue(queue*q);
extern void insertQueue(queue*q, int ch);
extern void deleteQueue(queue*q);
extern void tranverse(queue*q);
extern int isEmpty(queue*q);
//extern void clearup(queue*q);
#endif // !_DYNAMIC_QUEUE_H_
