#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char a;
	scanf("%c", &a);
	for (int i = 1; i <= 5; i+=2) {
		int k = 0, j = 0;
		for (; k < (5-i)/2; ++k)
		{
			/* code */
			printf(" ");
		}
		for (; j < i; j++)
		{
			printf("%c", a);
		}
		printf("\n");
	}
	for (int i = 3; i > 0; i-=2)	{
		int k = 0, j = 0;
		for (; k < (5-i)/2; ++k)
		{
			/* code */
			printf(" ");
		}
		for (; j < i; j++)
		{
			printf("%c", a);
		}
		printf("\n");
	}
	return 0;
}