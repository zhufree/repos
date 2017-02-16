#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/* 
	一个多项式可以表达为x的各次幂与系数乘积的和，比如：
    2x6+3x5+12x3+6x+20
	现在，你的程序要读入两个多项式，然后输出这两个多项式的和，
	也就是把对应的幂上的系数相加然后输出。
	程序要处理的幂最大为100。

	输入格式:
	总共要输入两个多项式，每个多项式的输入格式如下：
	每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，
	所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。
	注意第一行和最后一行之间不一定按照幂次降低顺序排列；
	如果某个幂次的系数为0，就不出现在输入数据中了；
	0次幂的系数为0时还是会出现在输入数据中。

	输出格式：
	从最高幂开始依次降到0幂，如：
	2x6+3x5+12x3-6x+20
	注意其中的x是小写字母x，而且所有的符号之间都没有空格，
	如果某个幂的系数为0则不需要有那项。 */
	int dxs[101] = {0};
	int count = 0;
	int mc, xs;
	while (scanf("%d %d", &mc, &xs) != -1) {
		// scanf("%d %d", &mc, &xs);
		dxs[mc] += xs;
		if (mc == 0) {
			count ++;
			if (count > 1) {
				break;
			}
		}
	}
	/*
	便利幂次数组，下标为幂次，值为系数，0~100,101个数
	系数为0，则不用输出
	系数不为0时，输出[+/-][系数]x[幂次]：
		幂次为1，不输出幂次，即[+/-][系数]x
		幂次为0，即常数项，不输出x，即[+/-][系数]
		系数为1，不输出系数，即[+/-]x[幂次]
			幂次为1，不输出幂次，即[+/-]x
			幂次为0，即常数项，不输出x，即[+/-]1
	*/
	int first = 1;
	char pat;
	for (int i = 100; i >= 0; --i) {
		// 第一个如果是+，不输出符号
		if (first == 1) {
			// printf("first==1\n");
			if (dxs[i] != 0) {
				// printf("xishu!=0\n");
				if (dxs[i] > 0) {
					// printf("xishu>0\n");
					pat = '+';
					if (dxs[i] == 1) {
						if (i == 1) {
							printf("x");
						} else if (i == 0) {
							printf("1");
						} else {
							printf("x%d", i);
						}
					} else {
						if (i == 1) {
							printf("%dx", abs(dxs[i]));
						} else if (i == 0) {
							printf("%d", abs(dxs[i]));
						} else {
							printf("%dx%d", abs(dxs[i]), i);
						}
					}
				} else {
					// printf("xishu <0\n");
					pat = '-';
					if (abs(dxs[i]) == 1) {
						// printf("-1~~~~~\n");
						if (i == 1) {
							printf("%cx", pat);
						} else if (i == 0) {
							printf("%c1", pat);
						} else {
							printf("%cx%d", pat, i);
						}
					} else {
						if (i == 1) {
							printf("%c%dx", pat, abs(dxs[i]));
						} else if (i == 0) {
							printf("%c%d", pat, abs(dxs[i]));
						} else {
							printf("%c%dx%d", pat, abs(dxs[i]), i);
						}
					}
				
				}
				first = 0;
			}
		} else {
			if (dxs[i] != 0) {
				if (dxs[i] > 0) {
					pat = '+';
				} else {
					pat = '-';
				}
				if (dxs[i] == 1) {
					if (i == 1) {
						printf("%cx", pat);
					} else if (i == 0) {
						printf("%c1", pat);
					} else {
						printf("%cx%d", pat, i);
					}
				} else {
					if (i == 1) {
						printf("%c%dx", pat, abs(dxs[i]));
					} else if (i == 0) {
						printf("%c%d", pat, abs(dxs[i]));
					} else {
						printf("%c%dx%d", pat, abs(dxs[i]), i);
					}
				}
			}
		}			
	}
	if (dxs[0] == 0) {
		printf("0");
	}
	printf("\n");
}
