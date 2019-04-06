#include <iostream>
#include <SqList.h>
#include <EX_Standard.h>

//via chamo
//调试：F9设置断点，F5运行程序，F10逐步调试，观察变量变化

/*------------------------------------------------------------------------------------------------*/
//2.3 initlist_sq 初始化
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
//2.4 listinsert_sq 插入
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
//2.5 listdelete_sq 删除元素
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
//主函数，可以把之前的使用范例COPY进来观察结果
/*------------------------------------------------------------------------------------------------*/
int main() {
	SqList L;
	ElemType temp;
	InitList_Sq(L);
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	printf("original\n");
	for (int i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i, L.elem[i - 1]);//输出序号1~listsize，数组中秩为0~listsize-1的数
	printf("\ndeleted\n");
	ListDelete_Sq(L, 2, temp);
	for (int i = 1;i <= L.length;i++) printf("L[%d]=%d\n", i, L.elem[i - 1]);


	getchar();								//等待输入enter
	return 0;
}