#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char translate(char c) {
	// A-Z:65-90
	// a-z:97-122
	if (((int)c >= 65&&(int)c <90) || ((int)c >= 97 && (int)c < 122)) {
		return (char)((int)c+1);
	} else if ((int)c == 90) {
		return 'A';
	} else if ((int)c == 122) {
		return 'a';
	}
	return c;
}
int main(int argc, char const *argv[]) {
	/*
	我们给出一种最简的的加密方法，对给定的一个字符串，
	把其中从a-y，A-Y的字母用其后继字母替代，把z和Z用a和A替代，其他非字母字符不变，则可得到一个简单的加密字符串。

	输入
	输入一行，包含一个字符串，长度小于80个字符。

	输出
	输出每行字符串的加密字符串。

	*/
	freopen("in.txt", "r", stdin);
	string line;
	getline(cin, line);
	// cout << line;
	for (int i = 0; line[i]; ++i)
	{
		line[i] = translate(line[i]);
	}
	cout << line << endl;
	return 0;
}