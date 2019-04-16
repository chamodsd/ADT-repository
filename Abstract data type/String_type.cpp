#include <iostream>
#include "String_type.h"

/*------------------------------------------------------------------------------------------------*/
//4.5 index ģʽƥ���㷨(����)
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






int Index_KMP(SString S, SString T, int pos);	//�㷨4.6��KMP�㷨
void get_next(SString T, int next[]);			//�㷨4.7����next����ֵ���㷨
void get_nextval(SString T, int nextval[]);		//�㷨4.8������next��������ֵ���㷨