#include <cstdio>
#include <iostream>

using namespace std;

int count2(int n) {
	int count = 0;
	if (n == 2) {
		count = 1;
		return count;
	}
	while(n > 10) {
		if (n%10 == 2) {
			count++;
		}
		n = n/10;
		// printf("n=%d\n", n);
	}
	if (n == 2) {
		count++;
	}
	return count;
}
int main(int argc, char const *argv[]) {
	/*
	请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
	比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。

	输入
	输入共 1 行，为两个正整数 L 和 R，之间用一个空格隔开。

	输出
	输出共 1 行，表示数字 2 出现的次数。
	*/
	// freopen("in.txt", "r", stdin);
	int L, R, count = 0;
	scanf("%d %d", &L, &R);
	for (int i = L; i <= R; ++i) {
		count += count2(i);
	}
	printf("%d\n", count);
	return 0;
}