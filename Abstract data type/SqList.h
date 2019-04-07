#pragma once
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <EX_Standard.h>

typedef int ElemType;

typedef struct{
	ElemType *elem;		
	//�洢�ռ��ַ��ע��elem��һ�����飬L.elem����һ����ַ��L.elem[i]�Ŵ���ֵ������i��0��ʼ��������Ӧ������Ǵ�1��ʼ��
	int length;
	int listsize;
}SqList;

Status compare(ElemType elem1, ElemType elem2);									//2.6���õ����еȺ���

Status InitList_Sq(SqList &L);													//2.3���캯��
Status ListInsert_Sq(SqList &L, int i, ElemType e);								//2.4����
Status ListDelete_Sq(SqList &L, int i, ElemType &e);							//2.5ɾ��
int LocateElem_sq(SqList L, ElemType e,Status(*compare)(ElemType, ElemType));	//2.6���Ҷ�λ
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);							//2.7˳���ĺϲ�




