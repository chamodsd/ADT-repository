#pragma once
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct{
	ElemType *elem;		
	//�洢�ռ��ַ��ע��elem��һ�����飬L.elem����һ����ַ��L.elem[i]�Ŵ���ֵ������i��0��ʼ��������Ӧ������Ǵ�1��ʼ��
	int length;
	int listsize;
}SqList;
