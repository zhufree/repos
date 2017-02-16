#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num;
	int even, odd = 0;
	scanf("%d", &num);
	while (num != -1) {
		if (num % 2 == 0) {
			even += 1;
		} else {
			odd += 1;
		}
		scanf("%d", &num);
	}
	printf("%d %d\n", odd, even);
	return 0;
}