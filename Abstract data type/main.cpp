#include <iostream>
#include "SqList.h"
#include "LinkList.h"
#include "EX_Standard.h"

int main() {
	/*------------------------------------------------------------------------------------------------*/
	/*下述语句说明while后面的条件只要大于0都算成立*/
	/*------------------------------------------------------------------------------------------------*/
	
	/*
	int i = 10;
	while (i - 1) { printf("%d\n", i);--i; }
	*/


	/*------------------------------------------------------------------------------------------------*/
	//顺序表
	/*------------------------------------------------------------------------------------------------*/

	/*
	SqList L, T, RES;
	int i;
	ElemType temp;
	//2.3 initlist
	InitList_Sq(L);
	InitList_Sq(T);
	InitList_Sq(RES);

	//2.4 listinsert_sq
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	ListInsert_Sq(L, 4, 6);
	ListInsert_Sq(L, 5, 9);
	for (i = 0;i <= 5;i++) ListInsert_Sq(T, i + 1, i);
	printf("original:\n");

	for (i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i - 1, L.elem[i - 1]);//输出序号1~listsize，数组中秩为0~listsize-1的数
	printf("\ndeleted:\n");

	//2.5 listdelete_sq
	ListDelete_Sq(L, 1, temp);

	for (i = 1;i <= L.length;i++) printf("L[%d]=%d\n", i - 1, L.elem[i - 1]);

	//2.6 locateelem_sq
	printf("\nlocate_result:\n%d\n", LocateElem_sq(L, 100, compare));

	//2.7 mergelist_sq
	printf("\nmerge_result:\n%d", LocateElem_sq(L, 100, compare));
	MergeList_Sq(L, T, RES);
	for (i = 1;i <= RES.length;i++)printf("RES[%d]=%d\n", i - 1, RES.elem[i - 1]);
	*/


	/*------------------------------------------------------------------------------------------------*/
	//单链表
	/*------------------------------------------------------------------------------------------------*/

	/*
	LNode *La, *Lb, *L;
	ElemType temp;

	//2.11
	CreateList_L(La, 3);
	printf("La:");
	Output_SL(La);

	CreateList_L(Lb, 3);
	printf("Lb:");
	Output_SL(Lb);

	//2.12
	MergeList_L(La, Lb, L);
	printf("L:");
	Output_SL(L);

	//2.8
	GetElem_L(L, 5, temp);
	printf("The 5th elem in L is %d.\n",temp);

	//2.9
	temp = 531;
	ListInsert_L(L, 2, temp);
	printf("L(inserted num %d):\n", temp);
	Output_SL(L);

	//2.10
	temp = NULL;
	ListDelete_L(L, 5, temp);
	printf("L(deleted num %d):\n", temp);
	Output_SL(L);
	*/



	getchar();								//防止之前输入过enter
	getchar();								//等待输入enter
	return 0;
}