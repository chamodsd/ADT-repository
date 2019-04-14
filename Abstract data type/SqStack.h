#pragma once

#include "EX_Standard.h"
/*------------------------------------------------------------------------------------------------*/
//顺序栈
/*------------------------------------------------------------------------------------------------*/
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S);			//构造空栈√
Status DestroyStack(SqStack &S);		//销毁栈S
Status ClearStack(SqStack &S);			//置空
Status StackEmpty(SqStack S);			//判空
int StackLength(SqStack S);				//返回S元素个数（即栈的长度）
Status GetTop(SqStack S, SElemType &e);	//用e返回栈顶元素【若栈不空】√
Status Push(SqStack &S, SElemType e);	//插入e为新的栈顶元素√
Status Pop(SqStack &S, SElemType &e);	//删除栈顶元素，用e返回其值【若栈不空】√
Status StackTraverse(SqStack S, Status(*visit)());
