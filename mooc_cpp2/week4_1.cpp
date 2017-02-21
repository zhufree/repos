#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void quickSort(int arr[], int left, int right) {
	int key = arr[left];
	if (left >= right) {
		return;
	}
	int i = left, j = right;
	while(i != j) {
		while(j > i && arr[j] <= key) {
			--j;
		}
		swap(arr[i], arr[j]);
		while(i < j && arr[i] >= key) {
			++i;
		}
		swap(arr[i], arr[j]);
	} // a[i] = key
	// printf("i=%d, arr[i]=%d\n", i, key);

	quickSort(arr, i + 1, right);
	quickSort(arr, left, i - 1);
}
void arrangeRight(int k, int arr[], int left, int right) {
	int key = arr[left];
	if (left >= right) {
		return;
	}
	int i = left, j = right;
	while(i != j) {
		while(j > i && arr[j] >= key) {
			--j;
		}
		swap(arr[i], arr[j]);
		while(i < j && arr[i] <= key) {
			++i;
		}
		swap(arr[i], arr[j]);
	} // a[i] = key
	// printf("i=%d, arr[i]=%d, k=%d\n", i, key, k);
	int r = right-i+1;
	if (r > k) {
		arrangeRight(k, arr, i + 1, right);
	} else if (r < k) {
		arrangeRight(k-r, arr, left, i - 1);
	} 
	// else {
		// quickSort(arr, i, right);
	// }
}

int main(int argc, char const *argv[]) {
	/*
	给定一个数组，统计前k大的数并且把这k个数从大到小输出。

	输入
	第一行包含一个整数n，表示数组的大小。n < 100000。
	第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。每个整数的绝对值不超过100000000。
	第三行包含一个整数k。k < n。

	输出
	从大到小输出前k大的数，每个数一行。

	*/
	// freopen("in.txt", "r", stdin);
	int n, k, count = 0;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	arrangeRight(k, arr, 0, n-1);
	quickSort(arr, n-k, n-1);
	for (int i = n-k; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}