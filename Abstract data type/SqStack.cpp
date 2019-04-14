#include <iostream>
#include "SqStack.h"

/*------------------------------------------------------------------------------------------------*/
//ADT Stack
/*------------------------------------------------------------------------------------------------*/
Status InitStack(SqStack &S) {
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType &e) {
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType *)realloc(S.base,
			(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

/*------------------------------------------------------------------------------------------------*/
//ADT Stack:stackempty(s)
/*------------------------------------------------------------------------------------------------*/
Status StackEmpty(SqStack S) {
	if (S.base == S.top) return 1;
	else return 0;
}


/*------------------------------------------------------------------------------------------------*/
//3.1 conversion 数制转换(10进制→8进制)
/*------------------------------------------------------------------------------------------------*/
void conversion() {
	SqStack S;
	int N;
	SElemType e;
	InitStack(S);
	scanf("%d", &N);
	while (N) {//可以通过每增加8，除以8以后的值加1来理解
		Push(S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
}

/*------------------------------------------------------------------------------------------------*/
//P49 MatchBrackets 括号匹配
/*------------------------------------------------------------------------------------------------*/
bool MatchBrackets() {
	SqStack S;
	InitStack(S);
	SElemType temp, EX;		//EX专门用来监控顶上的元素，其实并没有实际意义，测试用
	while ((temp = getchar())!='\n') {
		if (temp == '[' || temp == '(' || temp == ']' || temp == ')') {
			if (temp == ']'&& *(S.top - 1) == '[') Pop(S, temp);
			else if (temp == ')'&& *(S.top - 1) == '(') Pop(S, temp);
			else Push(S, temp);
			EX = *(S.top - 1);
		}
	}//while
	if (StackEmpty(S))return OK;
	else return ERROR;
}