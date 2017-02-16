#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	假设鸡尾酒疗法的有效率为x，新疗法的有效率为y，
	如果y-x大于5%，则效果更好，如果x-y大于5%，则效果更差，否则称为效果差不多。
	下面给 出n组临床对照实验，其中第一组采用鸡尾酒疗法，其他n-1组为各种不同的改进疗法。
	请写程序判定各种改进疗法效果如何。

	输入
	第一行为整数n（ 1 < n <= 20）；
	其余n行每行两个整数，第一个整数是临床实验的总病例数(小于等于10000)，
	第二个疗效有效的病例数。
	这n行数据中，第一行为鸡尾酒疗法的数据，其余各行为各种改进疗法的数据。
	
	输出
	有n-1行输出，分别表示对应改进疗法的效果：
	如果效果更好，输出better；如果效果更差，输出worse；否则输出same
	*/
	int n, dx, dy, x, y;
	double dr, r;
	scanf("%d", &n);
	int result[n];
	scanf("%d %d", &dx, &dy);
	dr = (double)dy/dx;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		// printf("%.5lf\n", (double)y/x);
		if (dr - (double)y/x > 0.05) {
			result[i-1] = -1;
		} else if ((double)y/x - dr > 0.05) {
			result[i-1] = 1;
		} else {
			result[i-1] = 0;
		}
	}
	for (int i = 0; i < n-1; ++i)
	{
		if (result[i] == 1) {
			printf("better\n");
		} else if (result[i] == -1) {
			printf("worse\n");
		} else {
			printf("same\n");
		}
	}
	return 0;
}