#pragma once

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;			//可以灵活改变·线性表用
typedef int SElemType;			//栈用

typedef int Status;				//众多函数都要用到
typedef int OperandType;		//3.4表达式求值用