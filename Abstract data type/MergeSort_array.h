#pragma once

typedef int AElemType;
#define MAX_NUM 200

void Merge_array(AElemType *array, AElemType *temp, int low, int mid, int high);	//归并两个相邻的有序子数组
void MSort_array(AElemType *array, AElemType *temp, int low, int high);				//对low~high序号内的元素看作一个数组进行归并排序，temp用于暂时存放数据
void MergeSort_array(AElemType *array, int length);												//归并排序的接口