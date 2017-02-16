#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	for (int i = 2; i < n; ++i) {
		while (n != 1) {
			if (n % i == 0) {
				n = n / i;
				if (n != 1) {
					printf("%dx", i);
				} else {
					printf("%d", i);
				}
			} else {
				break;
			}

		}
	}
	if (n != 1) {
		printf("%d", n);
	}
}