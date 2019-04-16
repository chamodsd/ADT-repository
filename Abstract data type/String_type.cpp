#include <iostream>
#include "String_type.h"

/*------------------------------------------------------------------------------------------------*/
//4.5 index 模式匹配算法(蛮力)
/*------------------------------------------------------------------------------------------------*/
int Index(SString S, SString T, int pos) {
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) { ++i;  ++j; }
		else { i = i - j + 2;  j = 1; }
	}
	if (j > T[0])return i - T[0];
	else return 0;
}






int Index_KMP(SString S, SString T, int pos);	//算法4.6：KMP算法
void get_next(SString T, int next[]);			//算法4.7：求next函数值的算法
void get_nextval(SString T, int nextval[]);		//算法4.8：计算next函数修正值的算法