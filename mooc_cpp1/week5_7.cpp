#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	输入一个n行m列的矩阵A，输出它的转置AT。

	输入
	第一行包含两个整数n和m，表示矩阵A的行数和列数。1 <= n <= 100，1 <= m <= 100。
	接下来n行，每行m个整数，表示矩阵A的元素。相邻两个整数之间用单个空格隔开，每个元素均在1~1000之间。

	输出
	m行，每行n个整数，为矩阵A的转置。相邻两个整数之间用单个空格隔开。
	样例输入
	3 3
	1 2 3
	4 5 6
	7 8 9
	样例输出
	1 4 7
	2 5 8
	3 6 9
	*/
	// freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	int raw[n][m], rev[m][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &raw[i][j]);
			rev[j][i] = raw[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", rev[i][j]);
		}	
		printf("\n");
	}

	return 0;
}