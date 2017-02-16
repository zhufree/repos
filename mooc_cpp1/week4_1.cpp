#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。如，假定初始整数为5，计算过程分别为16、8、4、2、1。 
	程序要求输入一个整数，将经过处理得到1的过程输出来。

	输入
	一个正整数N(N <= 2,000,000)
	
	输出
	从输入整数到1的步骤，每一步为一行，每一部中描述计算过程。最后一行输出"End"。如果输入为1，直接输出"End"。

	*/
	long int n;
	scanf("%ld", &n);
	while (n > 1) {
		if (n % 2 == 1) {
			printf("%ld*3+1=", n);
			n = n * 3 + 1;
			printf("%ld\n", n);
		} else {
			printf("%ld/2=", n);
			n = n / 2;
			printf("%ld\n", n);
		}
	}
	printf("End\n");
	return 0;
}