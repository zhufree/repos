#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	对于半径为r的球，其体积的计算公式为V=4/3*πr3，这里取π= 3.14。
	现给定r，求V,保留到小数点后2位。
	*/
	double r;
	scanf("%lf", &r);
	printf("%.2lf\n", (4/3.0)*3.14*r*r*r);
	return 0;
}