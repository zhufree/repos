#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	描述
	雇佣兵的体力最大值为M，初始体力值为0、战斗力为N、拥有X个能量元素。
	当雇佣兵的体力值恰好为M时，才可以参加一个为期M天的战斗期，战斗期结束体力值将为0。
	在同一个战斗期内，雇佣兵每连续战斗n天，战斗力就会上升1点，n为当前战斗期开始时的战斗力。
	一个战斗期结束后，雇佣兵需要用若干个能量元素使其体力恢复到最大值M，从而参加下一个战斗期。
	每个能量元素恢复的体力值不超过当前的战斗力。每个能量元素只能使用一次。
	请问：雇佣兵的战斗力最大可以到达多少。

	输入
	一行包括三个整数M、N、X，相邻两个整数之间用单个空格隔开。M、N、X均为不超过10000的正整数。

	输出
	输出一个整数，为雇佣兵的最大战斗力。
	*/
	// freopen("in.txt", "r", stdin);
	int M, N, X;
	scanf("%d %d %d", &M, &N, &X);
	int m = 0, n = N;
	while (X > 0) {
		// printf("n = %d\n", n);
		while(m < M) {
			m += n;
			X--;
			// printf("recover:m=%d,X=%d\n", m, X);
			if (X==0) {
				break;
			}
		}
		if (m<M) {
			break;
		} else {
			m = M;
		}
		while(m > 0) {
			m-=N;
			if (m < 0) {
				// N = n;
				break;
			} else {
				n++;
			}
			
			// printf("fight:m=%d,n=%d\n", m, n);
		}
		m = 0;
		N = n;
		if (X==0) {
			break;
		}
	}
	printf("%d\n", n);
	return 0;
}