// 数据结构第三次上机.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <queue>
using namespace std;
int const M = 20;
typedef int Elem;
typedef struct tagBinNode
{
	Elem data;
	struct tagBinNode *lc;
	struct tagBinNode *rc;
}BinNode;
typedef struct LNODE
{
	BinNode *root;
	LNODE *next;
}LNode;
void Count(char *file, int *statistic)
{
	int i = 0;
	while (file[i++] != 0)
		statistic[file[i - 1] - 97]++;
}
void OrderWeight(LNode **l, BinNode *ht) //二叉树的结点从小到大插入链表中
{
	LNode *ltemp, *lnew, *pl;
	lnew = new LNode;
	lnew->next = NULL;
	lnew->root = ht;
	pl = *l;
	ltemp = pl->next;
	while (ltemp != NULL)
	{
		if (lnew->root->data > ltemp->root->data)
		{
			ltemp = ltemp->next;
			pl = pl->next;
		}
		else
			ltemp = NULL;
	}
	lnew->next = pl->next;
	pl->next = lnew;
}
BinNode *Huffman(int *m)
{
	int i;
	LNode *l, *p1, *p2;
	BinNode *hnew, *h, *h1, *h2;
	l = new LNode;
	l->next = NULL;
	l->root = NULL;
	for (i = 0; i < 26; i++)
	{
		hnew = new BinNode;
		hnew->data = m[i];
		hnew->lc = NULL;
		hnew->rc = NULL;
		OrderWeight(&l, hnew);
	}
	while (l->next->next != NULL)  //至少有两棵树
	{
		p1 = l->next;
		p2 = p1->next;
		l->next = p2->next;
		h1 = p1->root;
		h2 = p2->root;
		delete p1;
		delete p2;
		h = new BinNode;
		h->data = h1->data + h2->data;
		h->lc = h1;
		h->rc = h2;
		OrderWeight(&l, h);
	}
	p1 = l->next;
	h = p1->root;
	delete l;
	return h;
}
void InOrder(BinNode *ht, int n)
{
	if (ht == NULL) return;
	InOrder(ht->lc, n + 1);
	if (ht->lc == NULL && ht->rc == NULL)
		cout << "权值为：" << ht->data << "." << "树的当前层数为：" << n << "." << endl;
	InOrder(ht->rc, n + 1);
}
int main()
{
	BinNode *head;
	char file[100] = { 0 };
	int m[26] = { 0 };
	int i = 0, j;
	double s = 0;
	FILE *fp;
	if ((fp = fopen("1.txt", "r")) == NULL)
	{
		printf("can't open 1.txt");
		return 1;
	}
	while (!feof(fp))
		fread(&file[i++], 1, 1, fp);
	fclose(fp);
	j = i;
	Count(file, m);
	head = Huffman(m);
	InOrder(head, 0);
	system("pause");
	return 0;
}