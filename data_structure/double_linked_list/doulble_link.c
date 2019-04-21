#include <cstdio>
#include <malloc.h>
#include"double_link.h"


typedef struct tagNode {
	struct tagNode *prev;
	struct tagNode *next;
	void* p;
} node;

//表头为空
static node* phead = nullptr;
static int count = 0;

//新建节点
static node* create_node(void *pval)
{
	
	node *pnode = NULL;
	pnode = (node*)malloc(sizeof(node));

	if (!pnode)
	{
		printf("create node error\n");
		return NULL;
	}

	pnode->next = pnode->prev = pnode;
	pnode->p = pval;
	return pnode;
}



int createDlist()
{
	phead = create_node(NULL);
	if (!phead) return 0;

	count = 0;
	return 1;
}

int isEmpty()
{
	return count == 0;

}

int sizeDlink()
{
	return count;
}

static node *getNode(int index)
{
	if (index < 0 || index>count)
	{
		printf("%s failed, the index is out of bound", __func__);
		return NULL;
	}
	if (index <= (count) / 2)
	{
		int i = 0;
		node* pnode = phead->next;
		while((i++)<index)
		{
			pnode = pnode->next;
			
		}
		return pnode;
	}

	int j = 0;
	int rindex = count - index - 1;
	node* rnode = phead->prev;
	while((j++)<rindex)
	{
		rnode = rnode->prev;
	}
	return rnode;
}

static node* get_first()
{
	return getNode(0);
}

static node* get_last()
{
	return getNode(count-1);
}

void * getDlink(int index)
{
	node *pindex = getNode(index);
	if (!pindex)
	{
		printf("%s failed\n", __func__);
		return NULL;
	}

	return pindex->p;
}

void* getFirst()
{
	return getDlink(0);
}

void * getEnd()
{
	return getDlink(count - 1);
}

int insertHead(void *pval)
{
	node *pnode = create_node(pval);
	if (!pnode) return 0;
	pnode->prev = phead;
	pnode->next = phead->next;
	phead->next->prev = pnode;
	phead->next = pnode;
	count++;
	return 1;
}

int insertEnd(void* pval)
{
	node *pnode = create_node(pval);
	if (!pnode) return 0;
	pnode ->prev = phead->prev;
	pnode->next = phead;
	phead->prev->next = pnode;
	phead->prev = pnode;
	return 1;
	
}

int insertDlink(int index, void* pval)
{
	if (index == 0) return insertHead(pval);
	node * pindex = getNode(index);
	if (!pindex) return 0;

	node *pnode = create_node(pval);
	if (!pnode) return 0;
	
	pnode->prev = pindex->prev;
	pnode->next = pindex;
	pindex->prev->next = pnode;
	pindex->prev = pnode;
	count++;
	return 1;
}

int deleteDlink(int index)
{
	node *pindex = getNode(index);
	if (!pindex) {
		printf("%s failed！the index is out of bound!", __func__);
		return 0;
	}
	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;
	free(pindex);
	count--;
	return 1;
}

int deleteHead()
{
	return deleteDlink(0);
}

int deleteEnd()
{
	return deleteDlink(count - 1);
}

int destoryDlink()
{
	if (!phead)
	{
		printf("%s fail, Dlink is null", __func__);
		return 0;
	}
	node *pnode = phead->next;
	node *ptemp=NULL;
	while (pnode != phead)
	{
		ptemp = pnode;
		pnode = pnode->next;
		free(ptemp);
	}

	free(phead);
	phead = NULL;
	count = 0;
	printf("detory done");
	return 1;


}

