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
Status StackEmpty(SqStack S);			//�п�
int StackLength(SqStack S);				//����SԪ�ظ�������ջ�ĳ��ȣ�
Status GetTop(SqStack S, SElemType &e);	//��e����ջ��Ԫ�ء���ջ���ա���
Status Push(SqStack &S, SElemType e);	//����eΪ�µ�ջ��Ԫ�ء�
Status Pop(SqStack &S, SElemType &e);	//ɾ��ջ��Ԫ�أ���e������ֵ����ջ���ա���
Status StackTraverse(SqStack S, Status(*visit)());
