//P38
//1.���һ���ݹ��㷨��ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľ�㡣

#include <iostream>
#include "LinkList.h"
#include "Linklist_questions.h"	//ע����ͷ�ļ��Ѿ���������Linklist.h������Ϊ�˷���������Ƿֿ�#include

void Del_x(LinkList &L, ElemType x) {
	LNode *p;		//ע�����������ĸ�ʽ��
	if (L == NULL) return;
	if (L->data == x) {
		p = L;
		L = L->next;
		free(p);	//�����������
		Del_x(L, x);
	}
	else
		Del_x(L->next, x);
}
//˼�������������ԭ�򣺿�������ΪL=L->next����������¸�ֵ��L����ֵ��L��data��next������Lԭ����ָ�Ľ��