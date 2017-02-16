#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

char *revstr(char *str, size_t len) {

    char *start = str;
    char *end = str + len - 1;
    char ch;

    if (str != NULL) {
        while (start < end) {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    return str;
}

char *toN(char *p, char res[],int n, int i) {
	p = res;
	while (n >= i) {
		*p++ = (char)(n%i+48);
		n = n / i;
	}
	*p = (char)(n+48);
	p = revstr(res, 3);
	return p;
}

int main(int argc, char const *argv[]) {
	/*
	一个十进制自然数,它的七进制与九进制表示都是三位数，且七进制与九进制的三位数码表示顺序正好相反。编程求此自然数,并输出显示。

	输入
	无。

	输出
	三行：
	第一行是此自然数的十进制表示；
	第一行是此自然数的七进制表示；
	第一行是此自然数的九进制表示。
	*/
	// 100(7) = 49, 1000(7) = 343
	// 100(9) = 81, 1000(9) = 729
	for (int i = 81; i <= 342; i++) {
		char res7[3];
		char res9[3];
		char *to7 = NULL, *rev7 = NULL;
		to7 = toN(to7, res7, i, 7);
		rev7 = revstr(to7, 3);
		char *to9 = NULL;
		to9 = toN(to9, res9, i, 9);
		if (rev7[0] == to9[0] && rev7[1]==to9[1] && rev7[2]==to9[2]) {
			printf("%d\n", i);
			printf("%s\n", revstr(rev7, 3));
			printf("%s\n", to9);
			free(to7);
			free(to9);
			free(rev7)
			break;
		}
	}
	return 0;
}