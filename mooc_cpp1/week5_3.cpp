#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	医院想统计一下某项疾病的获得与否与年龄是否有关，
	需要对以前的诊断记录进行整理，
	按照0-18、19-35、36-60、61以上（含61）四个年龄段统计的患病人数占总患病人数的比例。

	输入
	共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。

	输出
	按照0-18、19-35、36-60、61以上（含61）四个年龄段输出该段患病人数占总患病人数的比例，
	以百分比的形式输出，精确到小数点后两位。每个年龄段占一行，共四行。
	*/
	// freopen("in.txt", "r", stdin);
	int n, age;
	scanf("%d", &n);
	// int patients[n];
	double period[4] = {0,0,0,0};
	for (int i = 0; i < n; ++i)
	{
		// scanf("%d", &patients[i]);
		scanf("%d", &age);
		if (age >= 0 && age <= 18) {
			period[0]++;
		} else if (age >18 && age <=35) {
			period[1]++;
		} else if (age > 35 && age <= 60) {
			period[2]++;
		} else {
			period[3]++;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		period[i] = (double)period[i]/n;
		printf("%.2lf%%\n", period[i]*100);
	}
	return 0;
}