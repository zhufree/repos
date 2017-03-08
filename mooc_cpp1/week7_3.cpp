#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int translate(string s) {
	if (s == "Rock") {
		return 0;
	} else if (s == "Scissors") {
		return 1;
	} else {
		return -1; //paper
	}
}
int winner(int n1, int n2) {
	// result:0->tie, -1->n1 win, 1->n2 win
	// 0 win 1, 1 win -1, -1 win 0
	if (n1 == n2) {
		return 0;
	}
	if (n1 == 0) {
		if (n2 == 1) {
			return -1;
		} else {
			return 1;
		}
	}
	if (n1 == -1) {
		if (n2 == 1) {
			return 1;
		} else {
			return -1;
		}
	}
	if (n1 == 1) {
		if (n2 == 0) {
			return 1;
		} else {
			return -1;
		}
	}
}
int main(int argc, char const *argv[]) {
	/*
	游戏规则：石头打剪刀，布包石头，剪刀剪布。 
	现在，需要你写一个程序来判断石头剪子布游戏的结果。

	输入
	输入包括N+1行：
	第一行是一个整数N，表示一共进行了N次游戏。1 <= N <= 100。
	接下来N行的每一行包括两个字符串，表示游戏参与者Player1，Player2的选择（石头、剪子或者是布）：
	S1 S2
	字符串之间以空格隔开S1,S2只可能取值在{"Rock", "Scissors", "Paper"}（大小写敏感）中。

	输出
	输出包括N行，每一行对应一个胜利者（Player1或者Player2），或者游戏出现平局，则输出Tie。
	*/
	// freopen("in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int res = winner(translate(s1), translate(s2));
		if (res == -1) {
			cout << "Player1" << endl;
		} else if (res == 1) {
			cout << "Player2" << endl;
		} else if (res == 0) {
			cout << "Tie" << endl;
		}
	}
	return 0;
}