#include <iostream>
#include <SqList.h>
#include <EX_Standard.h>

//via chamo
//���ԣ�F9���öϵ㣬F5���г���F10�𲽵��ԣ��۲�����仯

/*------------------------------------------------------------------------------------------------*/
//2.3 initlist_sq ��ʼ��
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
//2.4 listinsert_sq ����
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
//2.5 listdelete_sq ɾ��Ԫ��
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
//�����������԰�֮ǰ��ʹ�÷���COPY�����۲���
/*------------------------------------------------------------------------------------------------*/
int main() {
	SqList L;
	ElemType temp;
	InitList_Sq(L);
	ListInsert_Sq(L, 1, 1);
	ListInsert_Sq(L, 2, 2);
	ListInsert_Sq(L, 3, 3);
	printf("original\n");
	for (int i = 1;i <= L.listsize;i++) printf("L[%d]=%d\n", i, L.elem[i - 1]);//������1~listsize����������Ϊ0~listsize-1����
	printf("\ndeleted\n");
	ListDelete_Sq(L, 2, temp);
	for (int i = 1;i <= L.length;i++) printf("L[%d]=%d\n", i, L.elem[i - 1]);


	getchar();								//�ȴ�����enter
	return 0;
}