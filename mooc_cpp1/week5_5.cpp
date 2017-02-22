#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	给定一个5*5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
	鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
	例如：在下面的例子中（第4行第1列的元素就是鞍点，值为8 ）。
	11 3 5 6 9
	12 4 7 8 10
	10 5 6 9 11
	8 6 4 7 2
	15 10 11 20 25

	输入
	输入包含一个5行5列的矩阵
	输出
	如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"
	*/
	// freopen("in.txt", "r", stdin);
	int arr[5][5];
	int found = 0;
	for (int i = 0; i < 5; ++i) {
		scanf("%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4]);
	}
	int realMax=0, maxRow=0, maxCol=0;
	for (int i = 0; i < 5; ++i) { // 遍历每行
		int max=0; // 该行中最大的数
		// printf("in line %d:", i);
		for (int j = 0; j < 5; ++j) { // 该行中的每一个数
			if (arr[i][j] > max) { //find the max
				// printf("max num is :%d\n", max);
				max  = arr[i][j]; 
				maxCol = j; // 最大数的列数
			}
		}
		// max num in this row
		// printf("max num is :%d\n", max);
		// 最大数在该列中是不是最小的
		int minRow=0;
		int min = arr[0][maxCol]; //初始最小值设定为该列第一个数
		for (int k = 0; k < 5; ++k) {
			if (arr[k][maxCol] < min) {
				min = arr[k][maxCol];
				minRow = k; // 该列最小值的行数
			}
		}
		// 如果恰好等于该行
		if (i == minRow) {
			realMax = max;
			maxRow = i;
			found = 1;
			break;
		}
	}
	if (found == 1) {
		printf("%d %d %d\n", maxRow+1, maxCol+1, realMax);
	} else {
		printf("not found\n");
	}
	return 0;
}
