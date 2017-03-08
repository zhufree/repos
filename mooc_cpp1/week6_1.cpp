#include <cstdio>
#include <iostream>

using namespace std;
unsigned long long arr[1000000];

int pell(int n) {
	for (int i = 0; i < n; ++i)
	{
		if (i <= 1) {
			arr[i] = (i+1)%32767;
		} else {
			arr[i] = (2*arr[i-1] + arr[i-2])%32767;
		}
	}
	return arr[n-1]%32767;
};

int main(int argc, char const *argv[]) {
	/*
	Pell数列a1, a2, a3, ...的定义是这样的，a1 = 1, a2 = 2, ... , an = 2 * an − 1 + an - 2 (n > 2)。
	给出一个正整数k，要求Pell数列的第k项模上32767是多少。

	输入
	第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1 ≤ k < 1000000)。

	输出
	n行，每行输出对应一个输入。输出应是一个非负整数。
	*/
	// freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		printf("%d\n", pell(m));
	}
	return 0;
}