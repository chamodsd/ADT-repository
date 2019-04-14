#pragma once

#include "EX_Standard.h"
/*------------------------------------------------------------------------------------------------*/
//˳��ջ
/*------------------------------------------------------------------------------------------------*/
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S);			//�����ջ��
Status DestroyStack(SqStack &S);		//����ջS
Status ClearStack(SqStack &S);			//�ÿ�
Status StackEmpty(SqStack S);			//�пա�
int StackLength(SqStack S);				//����SԪ�ظ�������ջ�ĳ��ȣ�
SElemType GetTop(SqStack S, SElemType &e);	//��e����ջ��Ԫ�ء���ջ���ա��̡�Ϊ���ڱ��ʽ��ֵ��������ʹ�ã�����ֵ��Ϊ��e��ע�������Ͳ����п��ˡ�
Status Push(SqStack &S, SElemType e);	//����eΪ�µ�ջ��Ԫ�ء�
Status Pop(SqStack &S, SElemType &e);	//ɾ��ջ��Ԫ�أ���e������ֵ����ջ���ա���
Status StackTraverse(SqStack S, Status(*visit)());

void conversion();						//3.1����ת����
bool MatchBrackets();					//P49����ƥ��ļ����
Status MazePath();						//P51/3.3�Թ�Ѱ·����δʵ�֣���

OperandType EvaluateExpression();		//3.4���ʽ��ֵ�����Ҫ����
int In(SElemType c);					//���ʽ��ֵ�õ����㷨���������ж�c�Ƿ���һ�����ţ��Դ˾������ĸ�ջ
char Precede(SElemType e, SElemType c);	//���ʽ��ֵ�õ����㷨�������ǱȽ�������������ȼ�
int operate(int a, char theta, int b);	//���ʽ��ֵ�õ����㷨�������Ǽ���a��b������a,bΪ������Ϊ���
SElemType calculate(SElemType &c, SElemType &num);		//�Լӣ����ʽ��ֵ�õ����㷨�������Ƕ�ȡ���������