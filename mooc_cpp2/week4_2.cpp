#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

long long merge(int arr[], int left, int mid, int right, int tmp[]) {
	int i = left,j = mid+1,k = left;
	long long count = 0;
	while(i <= mid && j <= right){
		if(arr[i]<=arr[j]){
			// 此处为稳定排序的关键，不能用小于
			tmp[k++]=arr[i++];
		} else {
			tmp[k++]=arr[j++];
			count+=j-k;// 每当后段的数组元素提前时，记录提前的距离
		}
	}
	while(i<=mid) {
		tmp[k++]=arr[i++];
	}
	while(j<=right){
		tmp[k++]=arr[j++];
	}
	for(i=left;i<=right;i++){
		// 写回原数组
		arr[i]=tmp[i];
	}
	return count;
}
long long mergeSortAndCount(int arr[], int left, int right, int tmp[]) {
	long long sum = 0;
	if (left < right) {
		int m = left + (right-left)/2;
		sum += mergeSortAndCount(arr, left, m, tmp);
		sum += mergeSortAndCount(arr, m+1, right, tmp);
		sum += merge(arr, left, m, right, tmp);
	}
	return sum;
}
int main(int argc, char const *argv[]) {
	/*
	对于不同的排名结果可以用逆序来评价它们之间的差异。考虑1,2,…,n的排列i1，i2，…，in，
	如果其中存在j,k，满足 j < k 且 ij > ik， 那么就称(ij,ik)是这个排列的一个逆序。
	一个排列含有逆序的个数称为这个排列的逆序数。
	例如排列 263451 含有8个逆序(2,1),(6,3),(6,4),(6,5),(6,1),(3,1),(4,1),(5,1)，
	因此该排列的逆序数就是8。显然，由1,2,…,n 构成的所有n!个排列中，最小的逆序数是0，对应的排列就是1,2,…,n；
	最大的逆序数是n(n-1)/2，对应的排列就是n,(n-1),…,2,1。逆序数越大的排列与原始排列的差异度就越大。
	现给定1,2,…,n的一个排列，求它的逆序数。

	输入
	第一行是一个整数n，表示该排列有n个数（n <= 100000)。
	第二行是n个不同的正整数，之间以空格隔开，表示该排列。

	输出
	输出该排列的逆序数。
	*/
	// freopen("in.txt", "r", stdin);
	int n, c = 0;
	scanf("%d", &n);
	int arr[n];
	int copy[n];
	long long result = 0;
	while(scanf("%d", &arr[c])!=-1) {
		c++;
	}
	result = mergeSortAndCount(arr, 0, n-1, copy);
	printf("%lld\n", result);
	return 0;
}