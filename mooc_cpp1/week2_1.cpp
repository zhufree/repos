#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	读入三个整数，按每个整数占8个字符的宽度，右对齐输出它们。
	*/
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%8d %8d %8d\n", a, b, c);
	return 0;
}