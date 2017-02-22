#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	输出一个整数序列中与指定数字相同的数的个数。

	输入
	输入包含三行：
	第一行为N，表示整数序列的长度(N <= 100)；
	第二行为N个整数，整数之间以一个空格分开；
	第三行包含一个整数，为指定的整数m。

	输出
	输出为N个数中与m相同的数的个数
	*/
	// freopen("in.txt", "r", stdin);
	int N, m, cnt = 0;
	scanf("%d", &N);
	int arr[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] == m) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}