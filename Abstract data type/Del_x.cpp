//P38
//1.设计一个递归算法，删除不带头节点的单链表L中所有值为x的结点。

#include <iostream>
#include "LinkList.h"
#include "Linklist_questions.h"	//注：该头文件已经包含上述Linklist.h，但是为了方便起见还是分开#include

void Del_x(LinkList &L, ElemType x) {
	LNode *p;		//注意这种声明的格式！
	if (L == NULL) return;
	if (L->data == x) {
		p = L;
		L = L->next;
		free(p);	//这样不会断链
		Del_x(L, x);
	}
	else
		Del_x(L->next, x);
}
//思考：不会断链的原因：可能是因为L=L->next本身就是重新赋值了L（赋值了L的data和next），而L原本所指的结点