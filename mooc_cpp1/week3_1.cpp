#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	给定一个整数，判断该数是奇数还是偶数。
	*/
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("even\n");
	} else {
		printf("odd\n");
	}
	return 0;
}