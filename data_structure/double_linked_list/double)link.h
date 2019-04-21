#pragma once
#ifndef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H

//可以分心啦，但是不专注就无法达到你的目标。自己决定把。
extern int createDlist(); //创建双链表，成功返回表头，失败返回null
extern int destoryDlink(); //撤销双链表，成功返回1，失败返回0；

extern int isEmpty(); //链表是否为空，空返回1，不空返回0
extern int sizeDlink();//返回链表的size
//要么目标别那么高。如果定的高，就得习惯枯燥、不安和孤独


extern void * getDlink(int index);//获取第i个元素，返回目标的指针
extern void* getFirst();//获取第一个元素，返回指针，失败则null
extern void* getLast();//获取最后一个元素，返回指针，失败则返回null。void*是任何类型的指针

extern int insertDlink(int index,void * pval);//在第index位置插入元素，成功返回1，失败0
extern int insertHead(void *pval);//在表头插入元素，成功1失败0
extern int insertEnd(void *pval);//在末尾插入元素，成功1失败0

extern int deleteDlink(int index);////在第index位置删除元素，成功返回1，失败0
extern int deleteHead();//在表头删除元素，成功1失败0
extern int deleteEnd();//在表头删除元素，成功1失败0

#endif
