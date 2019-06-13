#pragma once

int chamo_extra_1(int);		//仅仅调用了x的值（生成了x的一个拷贝，x本身不会变化）
int chamo_extra_2(int *);	//调用了x的地址
int chamo_extra_3(int &);	//调用了x的值，并且对x赋值会引起x的改变
int chamo_extra_4(int * &);	//???