#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/* 
	(0,1)之间的任何浮点数都可以表达为两个正整数的商，为了表达这样两个数的商，可以将相除的结果以多个整数来表示，
	每个整数表示结果的一位。即商的第一位用一个整数来表示，第二位用另一个整数来表示，
	以此类推，就可以输出一个高精度的除法结果了。
	如16/19的结果0.8421052631...就可以依次输出8、4、2、1、0、5、2、6、3、1...。

	而除法的过程，则可以模仿人工列竖式做除法的方式，先将被除数乘以10，得到一位商以后，将余数乘以10作为下一轮计算的被除数：
	    160/19->8余8
	    80/19->4余4
	    ...
	当某次余数为0时，则表明除尽。

	现在，请写一个程序，输入一个分数，计算出它的小数形式。无论是否可以除尽，输出最多小数点后200位。

	输入格式:
	形如
	    a/b
	的两个数，其中10<=a<b<100。也就是说，这个小数一定是小于1的正数。

	输出格式：
	形如
	    0.xxxxxxxxx
	的小数，小数点后最多200位。输出结束的时候要带着回车换行。
	如果a/b是一个有限不循环小数，则输出完所有的有效位就可以了，不需要再输出后面的0来凑满200位。
	*/
	int a, b, count = 0;
	scanf("%d/%d", &a, &b);
	// printf("a=%d, b=%d\n", a, b);
	int div, res;
	printf("0.");
    while (count < 200) {
    	div = a*10/b;
    	res = a*10%b;
    	if (res > 0) {
    		printf("%d", div);
    	} else {
    		printf("%d", div);
    		break;
    	}
    	a = res;
    	count ++;
    }
}