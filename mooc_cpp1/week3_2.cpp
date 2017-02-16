#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]) {
	/*
	利用公式:
	x1 = (-b + sqrt(b*b-4*a*c))/(2*a), 
	x2 = (-b - sqrt(b*b-4*a*c))/(2*a)
	求一元二次方程ax2+ bx + c =0的根，其中a不等于0。

	输入
	输入一行，包含三个浮点数a, b, c（它们之间以一个空格分开），
	分别表示方程ax2 + bx + c =0的系数。

	输出
	输出一行，表示方程的解。
	若b2 = 4 * a * c,则两个实根相等，则输出形式为：x1=x2=...。
	若b2 > 4 * a * c,则两个实根不等，则输出形式为：x1=...;x2 = ...，其中x1>x2。
	若b2 < 4 * a * c，则有两个虚根，则输出：x1=实部+虚部i; x2=实部-虚部i，
	即x1的虚部系数大于等于x2的虚部系数，实部为0时不可省略。
	实部 = -b / (2*a), 虚部 = sqrt(4*a*c-b*b) / (2*a)

	所有实数部分要求精确到小数点后5位，数字、符号之间没有空格。
	*/
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (b*b == 4*a*c) {
		printf("x1=x2=%.5lf\n", (-1*b)/(2*a));
	} else if (b*b > 4 * a * c) {
		printf("x1=%.5lf;x2=%.5lf\n", (-1*b+sqrt(b*b-4*a*c))/(2*a), (-1*b-sqrt(b*b-4*a*c))/(2*a));
	} else {
		double x = -b / (2*a), y = sqrt(4*a*c-b*b) / (2*a);
		if (x == 0) {
			x = -x;
		}
		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n", x, y, x, y);
	}
	return 0;
}