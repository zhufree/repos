#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	监护室每小时测量一次病人的血压，若收缩压在90 - 140之间并且舒张压在60 - 90之间（包含端点值）则称之为正常，现给出某病人若干次测量的血压值，计算病人保持正常血压的最长小时数。

	输入
	第一行为一个正整数n，n < 100
	其后有n行，每行2个正整数，分别为一次测量的收缩压和舒张压，中间以一个空格分隔。

	输出
	输出仅一行，血压连续正常的最长小时数。
	*/
	int n, a, b, max = 0, tmp = 0;
	// freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		if (a>=90&&a<=140&&b>=60&&b<=90) {
			tmp ++;
		} else {
			if (tmp > max) {
				max = tmp;
			}
			tmp = 0;
		}
		// printf("tmp = %d, max = %d\n", tmp, max);
	}
	if (tmp > max) {
		max = tmp;
	}
	printf("%d\n", max);
	return 0;
}