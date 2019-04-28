#include <iostream>
#include "MergeSort_array.h"
using namespace std;

/*
void Merge_array(AElemType *array, AElemType *temp, int low, int mid, int high);	//�鲢�������ڵ�����������
void MSort_array(AElemType *array, AElemType *temp, int low, int high);				//��low~high����ڵ�Ԫ�ؿ���һ��������й鲢����temp������ʱ�������
void MergeSort_array(AElemType *array);												//�鲢����Ľӿ�
*/

void Merge_array(AElemType *array, AElemType *temp, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = 0;
	int num = high - low + 1;				//�ܹ���Ԫ����
	while (i <= mid && j <= high) {
		if (array[i]<array[j])	*(temp + k++) = *(array + i++);
		else					*(temp + k++) = *(array + j++);
	}
	while (i <= mid)			*(temp + k++) = *(array + i++);
	while (j <= high)			*(temp + k++) = *(array + j++);
	//������������array[low..mid]��array[mid+1..high]�鲢Ϊһ����������󱣴�����temp[0..high-low]��
	for (i = low; i <= high; i++) {
		*(array + i) = *(temp + i - low);					//���ƻ�ԭ���顣���ʱ���ƺ�����ͨ���ȸ��ƣ��ٸ�ֵ�Ĳ���ʡȥ���������ܡ���Ϊ�Ƕ�һ��������N��Ԫ�أ�ֻ�������Ⱥ����⡣
	}
}

void MSort_array(AElemType *array, AElemType *temp, int low, int high) {
	if (low == high) return;
	else {
		int mid;
		mid = (low + high) / 2;						//��������Ϊlow~mid,mid+1~high��������
		MSort_array(array, temp, low, mid);			//�ݹ�Ĺ鲢����low~mid��ŵ�������
		MSort_array(array, temp, mid+1, high);		//�ݹ�Ĺ鲢����mid+1~high��ŵ�������
		Merge_array(array, temp, low, mid, high);	//�鲢low~mid,mid_1~high��ŵ�������
	}
}

void MergeSort_array(AElemType *array, int length) {
	AElemType temp[MAX_NUM];
	//��������ܿ���ͨ������O(n)��ʱ�䣬��֪����ĳ�������ʡ�ռ�
	//����ʹ�ǰ���Length�����ݽṹҲҪ������Щʱ�䣬��Ϊ���ʱ��ƽ̯����ÿһ�εļ��롤ɾ���У�
	MSort_array(array, temp, 0, length - 1);
}