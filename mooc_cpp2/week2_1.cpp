#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void swap_(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void range(char arr[], int len, int start){
	sort(arr+start, arr+len);
	if (start == len) {
		printf("%s\n", arr);
		return;
	} else {
		for (int i = start; i < len; ++i)
		{
			swap_(&arr[start], &arr[i]);
			range(arr, len, start+1);
			swap_(&arr[start], &arr[i]);
			sort(arr+start, arr+len);
		}
	}
};

int main(int argc, char const *argv[]) {
	/*
	给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。

	输入
	输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
	
	输出
	输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

	已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
	s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
	*/
	char arr[6];
	char c;
	scanf("%s", arr);
	int len = strlen(arr);
	range(arr, len, 0);
	return 0;
}