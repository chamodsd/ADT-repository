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

SElemType GetTop(SqStack S, SElemType &e) {
	if (S.top == S.base) return -1;
	e = *(S.top - 1);
	return e;
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
	//注：本算法的selemtype指的是char型，用int型需要做相应的修改
	SqStack S;
	InitStack(S);
	SElemType temp, EX;		
	//EX专门用来监控顶上的元素，其实并没有实际意义，测试用，当然也可以直接用基本操作gettop，这里为了加强对指针的理解才使用。
	while ((temp = getchar())!='\n') {
		if (temp == '[' || temp == '(' || temp == ']' || temp == ')') {
			if (temp == ']'&& *(S.top - 1) == '[') Pop(S, temp);	//注意这里指针的用法，不减一是没法判断的
			else if (temp == ')'&& *(S.top - 1) == '(') Pop(S, temp);
			else Push(S, temp);
			EX = *(S.top - 1);
		}
	}//while
	if (StackEmpty(S))return OK;
	else return ERROR;
}

/*------------------------------------------------------------------------------------------------*/
//3.4 EvaluateExpression 表达式求值
/*------------------------------------------------------------------------------------------------*/

int In(SElemType c) {
	char temp = char(c);
	if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '(' || temp == ')' || temp == '#')return 1;
	else return 0;
}

char Precede(SElemType c1, SElemType c2) {
	char temp1 = char(c1);
	char temp2 = char(c2);

	if (temp1 == '+' || temp1 == '-') {
		if (temp2 == '+')return '>';
		if (temp2 == '-')return '>';
		if (temp2 == '*')return '<';
		if (temp2 == '/')return '<';
		if (temp2 == '(')return '<';
		if (temp2 == ')')return '>';
		if (temp2 == '#')return '>';
	}
	if (temp1 == '*' || temp1 == '/') {
		if (temp2 == '+')return '>';
		if (temp2 == '-')return '>';
		if (temp2 == '*')return '>';
		if (temp2 == '/')return '>';
		if (temp2 == '(')return '<';
		if (temp2 == ')')return '>';
		if (temp2 == '#')return '>';
	}
	if (temp1 == '（') {
		if (temp2 == '+')return '<';
		if (temp2 == '-')return '<';
		if (temp2 == '*')return '<';
		if (temp2 == '/')return '<';
		if (temp2 == '(')return '<';
		if (temp2 == ')')return '=';
		//if (temp2 == '#')return '>';
	}
	if (temp1 == ')') {//可以合并成一句，为了清晰起见不合并
		if (temp2 == '+')return '>';
		if (temp2 == '-')return '>';
		if (temp2 == '*')return '>';
		if (temp2 == '/')return '>';
		//if (temp2 == '(')return '<';
		if (temp2 == ')')return '>';
		if (temp2 == '#')return '>';
	}
	if (temp1 == '#') {
		if (temp2 == '+')return '<';
		if (temp2 == '-')return '<';
		if (temp2 == '*')return '<';
		if (temp2 == '/')return '<';
		if (temp2 == '(')return '<';
		//if (temp2 == ')')return '';
		if (temp2 == '#')return '=';
	}
}

int operate(SElemType a, SElemType theta, SElemType b) {
	char temp = char(theta);
	if (temp == '+') return a + b;
	if (temp == '-') return a - b;
	if (temp == '*') return a * b;
	if (temp == '/') return a / b;//为了健壮性可能要用double型的a,b，这里假定可以整除
}

int calculate(SElemType &c, SElemType &num) {
	if (c >= 48 && c <= 57) {
		c -= 48;
		num *= 10;
		num += c;
	}
	return 0;
} 

OperandType EvaluateExpression() {
	//【注意表达式结束的标志是#】
	//【注意这里的gettop返回的是e的值，应该要稍作调整】
	//算术表达式求值的算符优先算法
	//OP:运算符集合
	//OPTR:运算符栈
	//OPND:运算数栈
	SqStack OPTR, OPND;
	SElemType e, c, a, b, x, theta;
	SElemType num = 0;//将要放进栈的数字计数

	InitStack(OPTR);
	Push(OPTR, int('#'));//强制类型转换，这样2个栈都是int型的，方便统一处理，使用时可以再强制类型转换转回
	InitStack(OPND);

	c = getchar();//书上是这么写的，但是这里不能用这个，不然的话就会输入1，读取的是字符1，转化为INT后变成49
	calculate(c, num);
	while (char(c) != '#' || char(GetTop(OPTR, e)) != '#') {
		if (!In(c)) {
			Push(OPND, c);
			c = getchar();
			calculate(c, num);
		}	//这里进行了一些改动，把In视作c的函数
		else
			//Push(OPND, num);
			//num = 0;
			switch (Precede(GetTop(OPTR, e), c)) {
			case'<'://栈顶元素优先权低
				Push(OPTR, c);
				c = getchar();
				calculate(c, num);
				break;
			case'='://脱括号并接收下一字符
				Pop(OPTR, x);
				c = getchar();	
				calculate(c, num);
				break;
			case'>'://退栈并将运算结果入栈
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, operate(a, theta, b));
				break;
			}//switch
	}//while
	return GetTop(OPND, e);
}

