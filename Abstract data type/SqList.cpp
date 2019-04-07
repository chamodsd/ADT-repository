#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SqList.h>
#include <EX_Standard.h>

//via chamo
//���ԣ�F9���öϵ㣬F5���г���F10�𲽵��ԣ��۲�����仯

//��������



/*------------------------------------------------------------------------------------------------*/
//2.3 initlist_sq ��ʼ�� O(1)
/*------------------------------------------------------------------------------------------------*/
Status InitList_Sq(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//ʹ�÷�����
/*	SqList L;
	InitList_Sq(L);
*/


/*------------------------------------------------------------------------------------------------*/
//2.4 listinsert_sq ���� O(n)
/*------------------------------------------------------------------------------------------------*/
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	ElemType *q, *p, *newbase;				//����û�У�����û����һ�䲻����������
	//----------�쳣���----------
	if (i<1 || i>L.length + 1) return ERROR;//����ֵ�Ƿ�

	if (L.length >= L.listsize) {			//�洢����
		newbase = (ElemType *)realloc(L.elem,
			(L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	//----------��Ҫ����----------
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p) * (p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}
//ʹ�÷�����
//������Կ�����δ��ֵ��Ԫ��Ϊ����ֵ
/*	SqList L;
	InitList_Sq(L);
	int temp = ListInsert_Sq(L, 1, 61);
	for (int i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i, L.elem[i]);
*/


/*------------------------------------------------------------------------------------------------*/
//2.5 listdelete_sq ɾ��Ԫ�� O(n)
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
//2.6 locateelem_sq Ѱ��Ԫ�� O(n)
/*------------------------------------------------------------------------------------------------*/
int LocateElem_sq(SqList L, ElemType e,
	Status(*compare)(ElemType, ElemType)) {
	int i;ElemType * p;
	i = 1;
	p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e))++i;
	if (i <= L.length) return i;//i��Ԫ�ص�λ��elem����+1
	else return 0;
}
//ע������Ҫ��������һ����������Ȼ�޷�ʹ����������
Status compare(ElemType elem1, ElemType elem2) {
	if (elem1 - elem2 == 0) return 1;
	else return 0;
}


/*------------------------------------------------------------------------------------------------*/
//2.7 mergelist_sq �ϲ�˳���
/*------------------------------------------------------------------------------------------------*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	//Ҫ��˳�����Ա�La��Lb����ֵ�ǵݼ�����
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
//�����������԰�֮ǰ��ʹ�÷���COPY�����۲���
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

	for (i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i-1, L.elem[i - 1]);//������1~listsize����������Ϊ0~listsize-1����
	printf("\ndeleted\n");

	//2.5 listdelete_sq
	ListDelete_Sq(L, 1, temp);

	for (i = 1;i <= L.length;i++) printf("L[%d]=%d\n", i-1, L.elem[i - 1]);

	//2.6 locateelem_sq
	printf("result:%d", LocateElem_sq(L, 100, compare));
	
	//2.7 mergelist_sq


	getchar();								//�ȴ�����enter
	return 0;
}