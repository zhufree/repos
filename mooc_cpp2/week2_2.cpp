#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int to2(int n) {
	for (int i = 0; i < 16; ++i) {
		if ((int)pow(2, i)<=n && (int)pow(2, i+1)>n) {
			return i;
		}
	}
}

void func(int n) {
	if (n == 2) {
		printf("2");
	} else if (n == 0) {
		printf("0");
	} else {
		int how2 = to2(n);
		// printf("how2 = %d\n", how2);
		if (how2 == 1) {
			func(2);
		} else {
			printf("2(");
			func(how2);
			printf(")");
		}
		int res = n - (int)pow(2, how2);
		// printf("pow = %d res=%d\n", (int)pow(2, how2), res);
		if (res != 0) {
			printf("+");
			func(res);	
		}
	}
	
}
int main(int argc, char const *argv[]) {
	/*
	任何一个正整数都可以用2的幂次方表示。例如：
    137=2^7+2^3+2^0
	同时约定方次用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：
	    2(7)+2(3)+2(0)
	进一步：7=2^2+2+2^0（2^1用2表示）
	        3=2+2^0
	所以最后137可表示为：
	    2(2(2)+2+2(0))+2(2+2(0))+2(0)
	又如：
	    1315=210+28+25+2+1
	所以1315最后可表示为：
	    2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

	输入
	一个正整数n（n≤20000）。

	输出
	一行，符合约定的n的0，2表示（在表示中不能有空格）。
	*/
	int n;
	scanf("%d", &n);
	func(n);
	
	return 0;
}