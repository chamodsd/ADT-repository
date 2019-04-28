#pragma once

#include "EX_Standard.h"

/*------------------------------------------------------------------------------------------------*/
//��̬����SLinkList
/*------------------------------------------------------------------------------------------------*/
#define MAXSIZE 20
typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;

typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;

/*------------------------------------------------------------------------------------------------*/
//��̬����SLinkList
/*------------------------------------------------------------------------------------------------*/
#define SIZE 100
typedef int RcdType;

typedef struct {
	RcdType rc;
	int next;
}SLNode;

typedef struct {
	SLNode r[SIZE];
	int length;
}SLinkListType;

/*------------------------------------------------------------------------------------------------*/
//��HeapType
/*------------------------------------------------------------------------------------------------*/
typedef SqList HeapType;

/*------------------------------------------------------------------------------------------------*/
//��̬������ʽ���������ã�
/*------------------------------------------------------------------------------------------------*/
#define MAX_NUM_OF_KEY 8
#define RADIX 10
#define MAX_SPACE 10000

typedef struct {
	KeyType keys[MAX_NUM_OF_KEY];
	InfoType otheritems;
	int next;
}SLCell;

typedef struct {
	SLCell r[MAX_SPACE];
	int keynum;
	int recnum;
}SLList;

/*------------------------------------------------------------------------------------------------*/
//�㷨
/*------------------------------------------------------------------------------------------------*/
void Insertsort(SqList &L);										//10.1ֱ�Ӳ�������
void BInsertsort(SqList &L);									//10.2�۰�����
void Arrange(SLinkListType &SL);								//10.3���������
void ShellInsert(SqList &L, int dk);							//10.4ϣ�������һ����ʽ
void Shellsort(SqList &l, int dlta[], int t);					//10.5ϣ�����򣨻��������Ч��ΪO(n)��

void Partition(SqList &L, int low, int high);					//10.6(b)��������(�����м�������¼��ֵ���������ͳһ��ֵ)
void QSort(SqList &L, int low, int high);						//10.7��������ĵݹ�汾
void QuickSort(SqList &L);										//10.8�������򣨻���������˻���ð������

void SelectSort(SqList &L);										//10.9��ѡ������
void HeapAdjust(HeapType &H, int s, int m);						//10.10�������һ��ɸѡ������
void HeapSort(HeapType &H);										//10.11������(�Լ�¼�����ٵ��ļ����ᳫ����n�ϴ���ļ�����Ч)

/*
void Merge(RcdType SR[], RcdType &TR[], int i, int m, int n);	//10.12��·�鲢
void MSort(RcdType SR[], RcdType &TR1[], int i, int m, int n);	//10.13��·�鲢�ĵݹ���ʽ
void MergeSort(SqList &L);										//10.14��·�鲢���� 
*/
//������·�鲢�����е����鲻�����ã���֪�������ϵ������ǳ���������󣬴���

