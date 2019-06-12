#include <iostream>
#include "LinkList.h"

/*------------------------------------------------------------------------------------------------*/
//2.8 getelem_l 寻找元素
/*------------------------------------------------------------------------------------------------*/
Status GetElem_L(LinkList L, int i, ElemType &e) {
	int j;
	LNode * p;//也可以写成linklist p

	p = L->next;
	j = 1;
	while (p&&j < i) {
		p = p->next;++j;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}


/*------------------------------------------------------------------------------------------------*/
//2.9 listinsert_l 插入
/*------------------------------------------------------------------------------------------------*/
Status ListInsert_L(LinkList &L, int i, ElemType e) {
	int j;
	LNode *p, *s;
	p = L;j = 0;
	while (p&&j < i - 1) { p = p->next; ++j; }
	if (!p || j > i - 1)return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;s->next = p->next;
	p->next = s;
	return OK;
}


/*------------------------------------------------------------------------------------------------*/
//2.10 listdelete_l 删除
/*------------------------------------------------------------------------------------------------*/
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	int j;
	LNode *p, *q;
	p = L; 	j = 0;
	while (p&&j < i - 1) { p->next;++j; }
	if (!(p->next || j > i - 1)) return ERROR;
	q = p->next;
	p->next = p->next->next;
	e = q->data;//要用e返回删除的值，但是不用return返回
	free(q);
	return OK;
}


/*------------------------------------------------------------------------------------------------*/
//2.11 createlist_l 头插法生成单链表
/*------------------------------------------------------------------------------------------------*/
//注：王道P28的做法是函数本身不含参数n，通过输入值是否为9999控制是否完成链表的创建。这样的话可以免去统计输入
//值个数的时间，（不知道输入的个数，只有链表的元素的时候尤其好用）是值得学习的办法。
void CreateList_L(LinkList &L, int n) {
	LNode *p;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//建立了一个带头结点的单链表
	for (i = n;i > 0;--i) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",&p->data);//书上是直接scanf(&p->data);
		p->next = L->next;//注意第一次运行的时候p指向NULL，但是第二次运行就不是了，插入到了头结点的后面
		L->next = p;
	}
}


/*------------------------------------------------------------------------------------------------*/
//2.12 mergelist_l 归并有序列表
/*------------------------------------------------------------------------------------------------*/
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
	LNode *pa, *pb, *pc;
	pa = La->next;//指向首元素而非头结点
	pb = Lb->next;
	Lc = pc = La;
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;pc = pa;pa = pa->next;
		}
		else { pc->next = pb;pc = pb;pb = pb->next; }
	}
	pc->next = pa ? pa : pb;
	free(Lb);//释放头结点
}


/*------------------------------------------------------------------------------------------------*/
//output_sl 从第一个元素开始输出链表（带头结点）
/*------------------------------------------------------------------------------------------------*/
void Output_SL(LinkList &L) {
	LNode *p = L->next;
	while (p) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}


/*------------------------------------------------------------------------------------------------*/
//2.13 locateelem_sl 在静态链表中寻找第一个值为e的数
/*------------------------------------------------------------------------------------------------*/
int LocateElem_SL(SLinkList S, ElemType e) {
	int i;
	i = S[0].cur;
	while (i&&S[i].data!=e)i = S[i].cur;
	return i;
}
