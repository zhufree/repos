#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

	输入
	一个字符串，长度小于100000。

	输出
	输出第一个仅出现一次的字符，若没有则输出no。
	*/
	freopen("in.txt", "r", stdin);
	int letters[26] = {0}; // 97-122->0-25
	bool flag = 0;
	char str[100000];
	scanf("%s", str);
	for (int i = 0; str[i]; ++i)
	{
		letters[(int)str[i]-97]++;
	}
	for (int i = 0; str[i]; ++i)
	{
		// cout << letters[i] << ",";
		if (letters[(int)str[i]-97] == 1) {
			cout << str[i] << endl;
			flag = 1;
			break;
		}
		
	}
	if (!flag) {
		cout << "no" << endl;
	}
	return 0;
}