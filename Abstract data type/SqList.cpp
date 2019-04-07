#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SqList.h>
#include <EX_Standard.h>

//via chamo
//调试：F9设置断点，F5运行程序，F10逐步调试，观察变量变化

//函数声明



/*------------------------------------------------------------------------------------------------*/
//2.3 initlist_sq 初始化 O(1)
/*------------------------------------------------------------------------------------------------*/
Status InitList_Sq(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//使用范例：
/*	SqList L;
	InitList_Sq(L);
*/


/*------------------------------------------------------------------------------------------------*/
//2.4 listinsert_sq 插入 O(n)
/*------------------------------------------------------------------------------------------------*/
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	ElemType *q, *p, *newbase;				//书上没有，但是没有这一句不能正常运行
	//----------异常情况----------
	if (i<1 || i>L.length + 1) return ERROR;//输入值非法

	if (L.length >= L.listsize) {			//存储已满
		newbase = (ElemType *)realloc(L.elem,
			(L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	//----------主要部分----------
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p) * (p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}
//使用范例：
//这里可以看到，未赋值的元素为任意值
/*	SqList L;
	InitList_Sq(L);
	int temp = ListInsert_Sq(L, 1, 61);
	for (int i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i, L.elem[i]);
*/


/*------------------------------------------------------------------------------------------------*/
//2.5 listdelete_sq 删除元素 O(n)
/*------------------------------------------------------------------------------------------------*/
Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	ElemType *p, *q;
	if ((i < 1) || (i >= L.length))return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p;p <= q;++p)*(p - 1) = *p;
	--L.length;
	return OK;
}


/*------------------------------------------------------------------------------------------------*/
//2.6 locateelem_sq 寻找元素 O(n)
/*------------------------------------------------------------------------------------------------*/
int LocateElem_sq(SqList L, ElemType e,
	Status(*compare)(ElemType, ElemType)) {
	int i;ElemType * p;
	i = 1;
	p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e))++i;
	if (i <= L.length) return i;//i是元素的位序，elem的秩+1
	else return 0;
}
//注意这里要定义这样一个函数，不然无法使用上述函数
Status compare(ElemType elem1, ElemType elem2) {
	if (elem1 - elem2 == 0) return 1;
	else return 0;
}


/*------------------------------------------------------------------------------------------------*/
//2.7 mergelist_sq 合并顺序表
/*------------------------------------------------------------------------------------------------*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	//要求顺序线性表La，Lb按照值非递减排列
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}


/*------------------------------------------------------------------------------------------------*/
//主函数，可以把之前的使用范例COPY进来观察结果
/*------------------------------------------------------------------------------------------------*/
int main() {
	SqList L;
	int i;
	ElemType temp;
	//2.3 initlist
	InitList_Sq(L);

	//2.4 listinsert_sq
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	ListInsert_Sq(L, 4, 6);
	ListInsert_Sq(L, 5, 9);
	printf("original\n");

	for (i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i-1, L.elem[i - 1]);//输出序号1~listsize，数组中秩为0~listsize-1的数
	printf("\ndeleted\n");

	//2.5 listdelete_sq
	ListDelete_Sq(L, 1, temp);

	for (i = 1;i <= L.length;i++) printf("L[%d]=%d\n", i-1, L.elem[i - 1]);

	//2.6 locateelem_sq
	printf("result:%d", LocateElem_sq(L, 100, compare));
	
	//2.7 mergelist_sq


	getchar();								//等待输入enter
	return 0;
}