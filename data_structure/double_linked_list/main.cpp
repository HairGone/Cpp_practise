// 双链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "double_link.h"
#include "pch.h"
#include <stdio.h>
#include "double_link.c"



void int_test()
{
	int iarr[4] = { 1, 2, 3, 4 };
	printf("\n__%s___\n", __func__);
	createDlist();
	insertDlink(0, &iarr[0]);
	insertDlink(0, iarr+1);
	insertDlink(1, &iarr[2]);

	printf("is empty %d\n", isEmpty());
	printf("size is %d\n", sizeDlink());

	int *p;
	for (int i = 0; i < sizeDlink(); i++)
	{
		p = (int*)getDlink(i);
		printf("dlink_get(%d)=%d\n", i, *p);
	}
	destoryDlink();
}
void string_test()
{
	const char* str[5] = {"I","am","best","Slam","Engineer" };
	//char *pt = (char*)str[0];
	printf("\n __%s__ \n",__func__);
	//printf("pt ==%s\n", pt+1);
	//char s[] = "sa";
	//printf("\n adress %d\n",  str[0]);
	//printf("\n adress %d\n", str[1]);
	//printf("\n adress %d\n",  str[2]);
	//printf("\n adress %d\n", str[3]);
	//printf("\n size %d\n",sizeof(pt));
	//printf("\n content %s\n", str[1]);
	createDlist();
	insertDlink(0, (char*)str[0]);
	insertDlink(1, (char*)str[1]);
	insertDlink(0, (char*)str[2]);

	char *p;
	for (int i = 0; i < sizeDlink(); i++)
	{
		p = (char*)getDlink(i);
		printf("dlink_get(%d)=%s\n", i, p);
	}
	destoryDlink();
}

//还有一个obj的链表下次做
//void obj_test();

int main()
{
	int_test();
	string_test();
	//obj_test();
	return 0;
}
