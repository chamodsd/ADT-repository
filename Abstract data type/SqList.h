#pragma once
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <EX_Standard.h>

typedef int ElemType;

typedef struct{
	ElemType *elem;		
	//存储空间基址，注意elem是一个数组，L.elem代表一个地址，L.elem[i]才代表值，并且i从0开始，但是相应的序号是从1开始的
	int length;
	int listsize;
}SqList;

Status compare(ElemType elem1, ElemType elem2);									//2.6会用到，判等函数

Status InitList_Sq(SqList &L);													//2.3构造函数
Status ListInsert_Sq(SqList &L, int i, ElemType e);								//2.4插入
Status ListDelete_Sq(SqList &L, int i, ElemType &e);							//2.5删除
int LocateElem_sq(SqList L, ElemType e,Status(*compare)(ElemType, ElemType));	//2.6查找定位
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);							//2.7顺序表的合并




