#include <iostream>
using namespace std;
#include "SqList.h"
#include "LinkList.h"
#include "SqStack.h"
#include "MergeSort_array.h"
#include "Linklist_questions.h"

 int main() {
	LinkList L;
	CreateList_L(L, 7);	//ע��ͷ�巨���������ɵģ���������L��ͷ���
	printf("L(before):");
	Output_SL(L);		//˳�����L

	Del_x(L, 5);

	printf("L(after):");
	Output_SL(L);		//˳�����L


	getchar();								//��ֹ֮ǰ�����enter
	getchar();								//�ȴ�����enter
	return 0;
}