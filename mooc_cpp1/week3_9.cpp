#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	给出一个整数a和一个正整数n，求乘方an。

	输入
	一行，包含两个整数a和n。-1000000 <= a <= 1000000，1 <= n <= 10000。
	
	输出
	一个整数，即乘方结果。题目保证最终结果的绝对值不超过1000000。
	*/
	int a, n, an = 1;
	scanf("%d %d", &a, &n);
	for (int i = 0; i < n; ++i)
	{
		an *= a;
	}
	printf("%d\n", an);
	return 0;
}