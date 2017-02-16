#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/*
	一只大象口渴了，要喝20升水才能解渴，
	但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。
	问大象至少要喝多少桶水才会解渴
	v = π*r*r*h
	*/
	int h, r;
	scanf("%d %d", &h, &r);
	double V = 3.14159*r*r*h/1000;
	// printf("%lf\n", V);
	printf("%d\n", (int)(20/V) + 1);
	return 0;
}