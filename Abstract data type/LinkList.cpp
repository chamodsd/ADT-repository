#include <iostream>
#include "LinkList.h"

/*------------------------------------------------------------------------------------------------*/
//2.8 getelem_l Ѱ��Ԫ��
/*------------------------------------------------------------------------------------------------*/
Status GetElem_L(LinkList L, int i, ElemType &e) {
	int j;
	LNode * p;//Ҳ����д��linklist p

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
//2.9 listinsert_l ����
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
//2.10 listdelete_l ɾ��
/*------------------------------------------------------------------------------------------------*/
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	int j;
	LNode *p, *q;
	p = L; 	j = 0;
	while (p&&j < i - 1) { p->next;++j; }
	if (!(p->next || j > i - 1)) return ERROR;
	q = p->next;
	p->next = p->next->next;
	e = q->data;//Ҫ��e����ɾ����ֵ�����ǲ���return����
	free(q);
	return OK;
}


/*------------------------------------------------------------------------------------------------*/
//2.11 createlist_l ͷ�巨���ɵ�����
/*------------------------------------------------------------------------------------------------*/
void CreateList_L(LinkList &L, int n) {
	LNode *p;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//������һ����ͷ���ĵ�����
	for (i = n;i > 0;--i) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",&p->data);//������ֱ��scanf(&p->data);
		p->next = L->next;//ע���һ�����е�ʱ��pָ��NULL�����ǵڶ������оͲ����ˣ����뵽��ͷ���ĺ���
		L->next = p;
	}
}


/*------------------------------------------------------------------------------------------------*/
//2.12 mergelist_l �鲢�����б�
/*------------------------------------------------------------------------------------------------*/
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
	LNode *pa, *pb, *pc;
	pa = La->next;//ָ����Ԫ�ض���ͷ���
	pb = Lb->next;
	Lc = pc = La;
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;pc = pa;pa = pa->next;
		}
		else { pc->next = pb;pc = pb;pb = pb->next; }
	}
	pc->next = pa ? pa : pb;
	free(Lb);//�ͷ�ͷ���
}


/*------------------------------------------------------------------------------------------------*/
//output_sl �ӵ�һ��Ԫ�ؿ�ʼ�����������ͷ��㣩
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
//2.13 locateelem_sl �ھ�̬������Ѱ�ҵ�һ��ֵΪe����
/*------------------------------------------------------------------------------------------------*/
int LocateElem_SL(SLinkList S, ElemType e) {
	int i;
	i = S[0].cur;
	while (i&&S[i].data!=e)i = S[i].cur;
	return i;
}