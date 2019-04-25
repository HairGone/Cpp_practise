// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
typedef struct _TREE
{
	int data;
	struct _TREE *left;
	struct _TREE *right;
} tree;

//preorder
void preorder(tree *tr)
{
	if (tr != NULL)
		/*	若二叉树非空，则执行以下操作：
			(01) 访问根结点；
			(02) 先序遍历左子树；
			(03) 先序遍历右子树。*/
	{
		printf("preoder data = %d \n", tr->data);
		preorder(tr->left);
		preorder(tr->right);
	}
}

void inorder(tree *tr)
{
	//若二叉树非空，则执行以下操作：
	//(01) 中序遍历左子树；
	//(02) 访问根结点；
	//(03) 中序遍历右子树。
	if (tr != NULL)
	{
		inorder(tr->left);
		printf("inorder data=%d\n", tr->data);
		inorder(tr->right);
	}

}

void postorder(tree *tr)
{
	/*(01) 后序遍历左子树；
	(02) 后序遍历右子树；
	(03) 访问根结点。*/
	if (tr != NULL)
	{
		postorder(tr->left);
		postorder(tr->right);
		printf("postorder data = %d\n", tr->data);
	}
		
}

int getheightpostorder(tree *tr)
{
	int lh, rh, max;
	if (tr != NULL)
	{
		lh = getheightpostorder(tr->left);
		rh = getheightpostorder(tr->right);
		max = (rh > lh) ? rh : lh;
		return max + 1;

	}
	else
		return 0;
}

int main()
{
	tree a, b, c, d, e, f;
	tree* root = &a;
	a.data = 1;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	e.data = 5;
	f.data = 6;
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = NULL;
	c.right = &f;
	d.right = d.left = NULL;
	e.left = e.right = NULL;
	f.left = f.right = NULL;

	printf("先序");
	preorder(root);

	printf("中序");
	inorder(root);

	printf("后序");
	postorder(root);

	printf("\n高度为：%d", getheightpostorder(root));

   
}
