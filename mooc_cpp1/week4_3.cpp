#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

	输入
	输入共 1 行，一个整数N。
	-1,000,000,000 ≤ N≤ 1,000,000,000。

	输出
	输出共 1 行，一个整数，表示反转后的新数。
	*/
	// freopen("in.txt", "r", stdin);
	int n, len = 0;
	bool less0 = false, first = true;
	int num[10];
	scanf("%d", &n);
	if (n < 0) {
		less0 = true;
		n = 0-n;
	}
	while(n > 10) {
		num[len] = n % 10;
		n = n / 10;
		len ++;
	}
	num[len] = n;
	if (less0) {
		printf("-");
	}

	for (int i = 0; i < len+1; ++i) {
		if (num[i]!=0 || !first) {
			printf("%d", num[i]);
			first = false;
		}
		
	}
	return 0;
}