#pragma once

#include "EX_Standard.h"
/*------------------------------------------------------------------------------------------------*/
//单链表
/*------------------------------------------------------------------------------------------------*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//注意LNode * 与LinkList是等价的,声明的时候两个都一样
//注意参数表中的引用参数可以直接用elemtype类型的e代替而不必特地建立引用参数elemtype & temp

Status GetElem_L(LinkList L, int i, ElemType &e);					//2.8寻找第i个元素并赋值给e
Status ListInsert_L(LinkList &L, int i, ElemType e);				//2.9在第i个位置插入值为e的元素
Status ListDelete_L(LinkList &L, int i, ElemType &e);				//2.10删除第i个位置的元素，并把删除元素的值赋给e
void CreateList_L(LinkList &L, int n);								//2.11头插法创建链表（逆序）
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);			//2.12归并两个有序链表（原本的链表不再存在）

void Output_SL(LinkList &L);										//从第一个元素开始输出链表（带头结点）

/*------------------------------------------------------------------------------------------------*/
//静态链表
/*------------------------------------------------------------------------------------------------*/

#define MAXSIZE 100

typedef struct {
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e);							//2.13在静态链表中寻找第一个值为e的数
