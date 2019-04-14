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
//3.1 conversion ����ת��(10���ơ�8����)
/*------------------------------------------------------------------------------------------------*/
void conversion() {
	SqStack S;
	int N;
	SElemType e;
	InitStack(S);
	scanf("%d", &N);
	while (N) {//����ͨ��ÿ����8������8�Ժ��ֵ��1�����
		Push(S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
}

/*------------------------------------------------------------------------------------------------*/
//P49 MatchBrackets ����ƥ��
/*------------------------------------------------------------------------------------------------*/
bool MatchBrackets() {
	//ע�����㷨��selemtypeָ����char�ͣ���int����Ҫ����Ӧ���޸�
	SqStack S;
	InitStack(S);
	SElemType temp, EX;		
	//EXר��������ض��ϵ�Ԫ�أ���ʵ��û��ʵ�����壬�����ã���ȻҲ����ֱ���û�������gettop������Ϊ�˼�ǿ��ָ�������ʹ�á�
	while ((temp = getchar())!='\n') {
		if (temp == '[' || temp == '(' || temp == ']' || temp == ')') {
			if (temp == ']'&& *(S.top - 1) == '[') Pop(S, temp);	//ע������ָ����÷�������һ��û���жϵ�
			else if (temp == ')'&& *(S.top - 1) == '(') Pop(S, temp);
			else Push(S, temp);
			EX = *(S.top - 1);
		}
	}//while
	if (StackEmpty(S))return OK;
	else return ERROR;
}

/*------------------------------------------------------------------------------------------------*/
//3.4 EvaluateExpression ���ʽ��ֵ
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
	if (temp1 == '��') {
		if (temp2 == '+')return '<';
		if (temp2 == '-')return '<';
		if (temp2 == '*')return '<';
		if (temp2 == '/')return '<';
		if (temp2 == '(')return '<';
		if (temp2 == ')')return '=';
		//if (temp2 == '#')return '>';
	}
	if (temp1 == ')') {//���Ժϲ���һ�䣬Ϊ������������ϲ�
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
	if (temp == '/') return a / b;//Ϊ�˽�׳�Կ���Ҫ��double�͵�a,b������ٶ���������
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
	//��ע����ʽ�����ı�־��#��
	//��ע�������gettop���ص���e��ֵ��Ӧ��Ҫ����������
	//�������ʽ��ֵ����������㷨
	//OP:���������
	//OPTR:�����ջ
	//OPND:������ջ
	SqStack OPTR, OPND;
	SElemType e, c, a, b, x, theta;
	SElemType num = 0;//��Ҫ�Ž�ջ�����ּ���

	InitStack(OPTR);
	Push(OPTR, int('#'));//ǿ������ת��������2��ջ����int�͵ģ�����ͳһ����ʹ��ʱ������ǿ������ת��ת��
	InitStack(OPND);

	c = getchar();//��������ôд�ģ��������ﲻ�����������Ȼ�Ļ��ͻ�����1����ȡ�����ַ�1��ת��ΪINT����49
	calculate(c, num);
	while (char(c) != '#' || char(GetTop(OPTR, e)) != '#') {
		if (!In(c)) {
			Push(OPND, c);
			c = getchar();
			calculate(c, num);
		}	//���������һЩ�Ķ�����In����c�ĺ���
		else
			//Push(OPND, num);
			//num = 0;
			switch (Precede(GetTop(OPTR, e), c)) {
			case'<'://ջ��Ԫ������Ȩ��
				Push(OPTR, c);
				c = getchar();
				calculate(c, num);
				break;
			case'='://�����Ų�������һ�ַ�
				Pop(OPTR, x);
				c = getchar();	
				calculate(c, num);
				break;
			case'>'://��ջ������������ջ
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, operate(a, theta, b));
				break;
			}//switch
	}//while
	return GetTop(OPND, e);
}

