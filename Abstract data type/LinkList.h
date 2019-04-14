#pragma once

#include "EX_Standard.h"
/*------------------------------------------------------------------------------------------------*/
//������
/*------------------------------------------------------------------------------------------------*/
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//ע��LNode * ��LinkList�ǵȼ۵�,������ʱ��������һ��
//ע��������е����ò�������ֱ����elemtype���͵�e����������صؽ������ò���elemtype & temp

Status GetElem_L(LinkList L, int i, ElemType &e);					//2.8Ѱ�ҵ�i��Ԫ�ز���ֵ��e
Status ListInsert_L(LinkList &L, int i, ElemType e);				//2.9�ڵ�i��λ�ò���ֵΪe��Ԫ��
Status ListDelete_L(LinkList &L, int i, ElemType &e);				//2.10ɾ����i��λ�õ�Ԫ�أ�����ɾ��Ԫ�ص�ֵ����e
void CreateList_L(LinkList &L, int n);								//2.11ͷ�巨������������
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);			//2.12�鲢������������ԭ���������ٴ��ڣ�

void Output_SL(LinkList &L);										//�ӵ�һ��Ԫ�ؿ�ʼ���������ͷ��㣩

/*------------------------------------------------------------------------------------------------*/
//��̬����
/*------------------------------------------------------------------------------------------------*/

#define MAXSIZE 100

typedef struct {
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e);							//2.13�ھ�̬������Ѱ�ҵ�һ��ֵΪe����
