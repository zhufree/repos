#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

int divide(int n, int m) {
	if (m == 1) {
		return 1; // {1,...1}
	} else if (n < m) {
		return divide(n, n); // n is max
	} else if (n == m) {
		return 1+divide(n, n-1); // 1 + divide(n, n-1);
	} else {
		return divide(n-m, m) + divide(n, m-1); 
		//划分中包含m的情况，即{m, {x1,x2,...xi}}, 其中{x1,x2,... xi} 的和为n-m，因此这情况下为f(n-m,m)
		//划分中不包含m的情况，则划分中所有值都比m小，即n的(m-1)划分，个数为f(n,m-1);
		//因此 f(n, m) = f(n-m, m)+f(n,m-1);
	}
}
int main(int argc, char const *argv[]) {
	/*
	将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
	正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。

	输入
	标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。
	输出
	对于每组测试数据，输出N的划分数。
	*/
	freopen("in.txt", "r", stdin);
	int N;
	while(scanf("%d\n", &N)!=-1) {
		printf("%d\n", divide(N, N));
	}
	// printf("%d\n", divide(50, 50));
	return 0;
}