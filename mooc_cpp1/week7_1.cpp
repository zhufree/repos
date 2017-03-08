#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	输入一行字符，统计出其中数字字符的个数。

	输入
	一行字符串，总长度不超过255。

	输出
	输出为1行，输出字符串里面数字字符的个数。
	*/
	freopen("in.txt", "r", stdin);
	string str;
	int count = 0;
	getline(cin, str);
	int len = str.length();
	// char line[255];
	// cin.getline(line, 255);
	// cout << line;
	for (int i = 0; i < len; ++i) {
		cout << (int)str[i]<< " ";
		int n = (int)str[i];
		if (n >= 48 && n <= 57) {
			count++;
		}
	}
	
	cout << count;
	return 0;
}