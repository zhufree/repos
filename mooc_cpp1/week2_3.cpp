#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	读入一个字符，一个整数，一个单精度浮点数，一个双精度浮点数，
	然后按顺序输出它们，并且要求在他们之间用一个空格分隔。输出浮点数时保留6位小数。
	*/
	char a;
	int b;
	float c;
	double d;
	scanf("%c %d %f %lf", &a, &b, &c, &d);
	printf("%c %d %.6f %.6lf\n", a, b, c, d);
	return 0;
}