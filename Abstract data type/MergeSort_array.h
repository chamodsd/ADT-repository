#pragma once

typedef int AElemType;
#define MAX_NUM 200

void Merge_array(AElemType *array, AElemType *temp, int low, int mid, int high);	//�鲢�������ڵ�����������
void MSort_array(AElemType *array, AElemType *temp, int low, int high);				//��low~high����ڵ�Ԫ�ؿ���һ��������й鲢����temp������ʱ�������
void MergeSort_array(AElemType *array, int length);												//�鲢����Ľӿ�