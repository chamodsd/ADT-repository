#pragma once
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct{
	ElemType *elem;		
	//存储空间基址，注意elem是一个数组，L.elem代表一个地址，L.elem[i]才代表值，并且i从0开始，但是相应的序号是从1开始的
	int length;
	int listsize;
}SqList;
