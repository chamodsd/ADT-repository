#include <iostream>

int chamo_extra_1(int x) {	//x是int型
	x = 100;	//x（保存在*x地址上的值）本身不会改变，仅仅在该函数内部值变为100
	return 0;
}

int chamo_extra_2(int *x) { //x是int *型
	*x = 100;	//x是一个指针，*x表示调用了指针所指地址上的int型变量x，这里对它赋值等同于确实改变了x
	return 0;
}

int chamo_extra_3(int &x) {	//x是int型
	x = 100;	//x确实变成100了（即使在函数外部也改变了）
	return 0;
}

int chamo_extra_4(int * &x) {
	*x = 100;
	return 0;
}