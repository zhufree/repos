#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	读入一个双精度浮点数，保留12位小数，输出这个浮点数。
	*/
	double x;
	scanf("%lf", &x);
	printf("%.12f\n", x);
	return 0;
}