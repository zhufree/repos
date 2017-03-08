#include <cstdio>
#include <iostream>

using namespace std;

int bitManipulation1(int n, int m, int i) {
// 在此处补充你的代码
	return (m>>i)|n;
}

int main(int argc, char const *argv[]) {
	/*
	写出函数中缺失的部分，使得函数返回值为一个整数,该整数的第i位和m的第i位相同，其他位和n相同。
	请使用【一行代码】补全bitManipulation1函数使得程序能达到上述的功能

	输入
	第一行是整数 t，表示测试组数。
	每组测试数据包含一行，是三个整数 n, m 和 i (0<=i<=31)
	输出
	对每组输入数据，每行输出整型变量n变化后的结果
	*/
	freopen("in.txt", "r", stdin);
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}