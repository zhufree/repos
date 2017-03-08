#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	输入1行句子（不多于200个单词，每个单词长度不超过100），只包含字母、空格和逗号。
	单词由至少一个连续的字母构成，空格和逗号都是单词间的间隔。
	试输出第1个最长的单词和第1个最短单词。 

	输入
	一行句子。
	输出
	两行输出：
	第1行，第一个最长的单词。
	第2行，第一个最短的单词。
	*/
	// freopen("in.txt", "r", stdin);
	int letlen[100] = {0}; // store nums count that len is 1~100
	string words[200];
	string line;
	getline(cin, line);
	int start = 0, wordcount = 0;
	// split words
	for (int i = 0; line[i]; ++i) {
		if (isspace(line[i])) {
			if (ispunct(line[i-1])) {
				words[wordcount] = line.substr(start, (i-start)-1);
			} else {
				words[wordcount] = line.substr(start, (i-start));
			}
			// cout << words[wordcount] << ",";
			start = i+1;
			wordcount++;
		}
	}
	words[wordcount] = line.substr(start);
	// cout << words[wordcount] << endl;
	
	wordcount++;
	// count letters
	for (int i = 0; i < wordcount; ++i) {
		// cout << words[i].length() << endl;
		letlen[words[i].length()]++;
	}
	int min, max;
	// find min length
	for (int i = 0; i < 100; ++i)
	{
		if (letlen[i] > 0) {
			min = i;
			break;
		}
	}
	// find max
	for (int i = 99; i > 0; --i)
	{
		if (letlen[i] > 0) {
			max = i;
			break;
		}
	}
	// cout << max << "," << min << endl;
	for (int i = 0; i < wordcount; ++i) {
		if (words[i].length() == max) {
			cout << words[i] << endl;
			break;
		}
	}
	for (int i = 0; i < wordcount; ++i) {
		if (words[i].length() == min) {
			cout << words[i] << endl;
			break;
		}
	}
	return 0;
}