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
Status StackEmpty(SqStack S);			//判空○
int StackLength(SqStack S);				//返回S元素个数（即栈的长度）
SElemType GetTop(SqStack S, SElemType &e);	//用e返回栈顶元素【若栈不空】√【为了在表达式求值里能正常使用，返回值改为了e，注意这样就不能判空了】
Status Push(SqStack &S, SElemType e);	//插入e为新的栈顶元素√
Status Pop(SqStack &S, SElemType &e);	//删除栈顶元素，用e返回其值【若栈不空】√
Status StackTraverse(SqStack S, Status(*visit)());

void conversion();						//3.1数制转换√
bool MatchBrackets();					//P49括号匹配的检验√
Status MazePath();						//P51/3.3迷宫寻路（尚未实现）×

OperandType EvaluateExpression();		//3.4表达式求值☆（很重要！）
int In(SElemType c);					//表达式求值用到的算法，作用是判断c是否是一个符号，以此决定进哪个栈
char Precede(SElemType e, SElemType c);	//表达式求值用到的算法，作用是比较两个算符的优先级
int operate(int a, char theta, int b);	//表达式求值用到的算法，作用是计算aθb，其中a,b为数，θ为算符
SElemType calculate(SElemType &c, SElemType &num);		//自加，表达式求值用到的算法，作用是读取输入的数字