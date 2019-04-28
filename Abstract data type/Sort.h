#pragma once

#include "EX_Standard.h"

/*------------------------------------------------------------------------------------------------*/
//静态链表SLinkList
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
//静态链表SLinkList
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
//堆HeapType
/*------------------------------------------------------------------------------------------------*/
typedef SqList HeapType;

/*------------------------------------------------------------------------------------------------*/
//静态链表（链式基数排序用）
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
//算法
/*------------------------------------------------------------------------------------------------*/
void Insertsort(SqList &L);										//10.1直接插入排序
void BInsertsort(SqList &L);									//10.2折半排序
void Arrange(SLinkListType &SL);								//10.3表插入排序
void ShellInsert(SqList &L, int dk);							//10.4希尔排序的一般形式
void Shellsort(SqList &l, int dlta[], int t);					//10.5希尔排序（基本有序→效率为O(n)）

void Partition(SqList &L, int low, int high);					//10.6(b)快速排序(不在中间给枢轴记录赋值而是在最后统一赋值)
void QSort(SqList &L, int low, int high);						//10.7快速排序的递归版本
void QuickSort(SqList &L);										//10.8快速排序（基本有序→退化成冒泡排序）

void SelectSort(SqList &L);										//10.9简单选择排序
void HeapAdjust(HeapType &H, int s, int m);						//10.10堆排序的一次筛选（？）
void HeapSort(HeapType &H);										//10.11堆排序(对记录数较少的文件不提倡，对n较大的文件很有效)

/*
void Merge(RcdType SR[], RcdType &TR[], int i, int m, int n);	//10.12二路归并
void MSort(RcdType SR[], RcdType &TR1[], int i, int m, int n);	//10.13二路归并的递归形式
void MergeSort(SqList &L);										//10.14二路归并排序 
*/
//上述二路归并方法中的数组不可引用，不知道是书上的谬误还是程序里的谬误，待查

