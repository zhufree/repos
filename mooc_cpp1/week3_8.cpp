#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	2008年北京奥运会，A国的运动员参与了n天的决赛项目(1≤n≤17)。
	现在要统计一下A国所获得的金、银、铜牌数目及总奖牌数。

	输入
	输入n＋1行，第1行是A国参与决赛项目的天数n，
	其后n行，每一行是该国某一天获得的金、银、铜牌数目，以一个空格分开。
	
	输出
	输出1行，包括4个整数，为A国所获得的金、银、铜牌总数及总奖牌数，以一个空格分开。
	*/
	int n, dx, dy, dz, x = 0, y = 0, z = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &dx, &dy, &dz);
		x += dx;
		y += dy;
		z += dz;
	}
	printf("%d %d %d %d\n", x, y, z, x + y + z);
	return 0;
}