#include <iostream>

int chamo_extra_1(int x) {	//x��int��
	x = 100;	//x��������*x��ַ�ϵ�ֵ��������ı䣬�����ڸú����ڲ�ֵ��Ϊ100
	return 0;
}

int chamo_extra_2(int *x) { //x��int *��
	*x = 100;	//x��һ��ָ�룬*x��ʾ������ָ����ָ��ַ�ϵ�int�ͱ���x�����������ֵ��ͬ��ȷʵ�ı���x
	return 0;
}

int chamo_extra_3(int &x) {	//x��int��
	x = 100;	//xȷʵ���100�ˣ���ʹ�ں����ⲿҲ�ı��ˣ�
	return 0;
}

int chamo_extra_4(int * &x) {
	*x = 100;
	return 0;
}