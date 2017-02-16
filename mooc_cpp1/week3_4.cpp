#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。
	虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，
	那么经过y小时你还有多少个完整的苹果？
	*/
	int n, x, y, m;
	scanf("%d %d %d", &n, &x, &y);
	if (y % x == 0) {
	 	m = y / x;
	} else {
	 	m = y / x + 1;
	}
	if (n > m) {
		printf("%d\n", n - m);		
	} else {
		printf("0\n");
	}
	return 0;
}