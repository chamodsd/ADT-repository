#include <iostream>
#include "MergeSort_array.h"
using namespace std;

/*
void Merge_array(AElemType *array, AElemType *temp, int low, int mid, int high);	//归并两个相邻的有序子数组
void MSort_array(AElemType *array, AElemType *temp, int low, int high);				//对low~high序号内的元素看作一个数组进行归并排序，temp用于暂时存放数据
void MergeSort_array(AElemType *array);												//归并排序的接口
*/

void Merge_array(AElemType *array, AElemType *temp, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = 0;
	int num = high - low + 1;				//总共的元素数
	while (i <= mid && j <= high) {
		if (array[i]<array[j])	*(temp + k++) = *(array + i++);
		else					*(temp + k++) = *(array + j++);
	}
	while (i <= mid)			*(temp + k++) = *(array + i++);
	while (j <= high)			*(temp + k++) = *(array + j++);
	//至此有序数组array[low..mid]和array[mid+1..high]归并为一个有序数组后保存在了temp[0..high-low]中
	for (i = low; i <= high; i++) {
		*(array + i) = *(temp + i - low);					//复制回原数组。这个时间似乎可以通过先复制，再赋值的操作省去。×并不能。因为那都一样复制了N个元素，只不过是先后问题。
	}
}

void MSort_array(AElemType *array, AElemType *temp, int low, int high) {
	if (low == high) return;
	else {
		int mid;
		mid = (low + high) / 2;						//二分数组为low~mid,mid+1~high的子数组
		MSort_array(array, temp, low, mid);			//递归的归并排序low~mid序号的子数组
		MSort_array(array, temp, mid+1, high);		//递归的归并排序mid+1~high序号的子数组
		Merge_array(array, temp, low, mid, high);	//归并low~mid,mid_1~high序号的子数组
	}
}

void MergeSort_array(AElemType *array, int length) {
	AElemType temp[MAX_NUM];
	//↑这个可能可以通过花费O(n)的时间，得知数组的长度来节省空间
	//（即使是包含Length的数据结构也要花费这些时间，因为这个时间平摊到了每一次的加入·删除中）
	MSort_array(array, temp, 0, length - 1);
}