#include <iostream>
using namespace std;
#include "SqList.h"
#include "LinkList.h"
#include "SqStack.h"
#include "MergeSort_array.h"
#include "Linklist_questions.h"

 int main() {
	LinkList L;
	CreateList_L(L, 7);	//注意头插法是逆序生成的，而且这里L带头结点
	printf("L(before):");
	Output_SL(L);		//顺序输出L

	Del_x(L, 5);

	printf("L(after):");
	Output_SL(L);		//顺序输出L


	getchar();								//防止之前输入过enter
	getchar();								//等待输入enter
	return 0;
}