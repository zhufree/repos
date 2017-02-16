# include <stdio.h>

int main() {
	int num, x, y, z;
	scanf("%d", &num);
	z = num % 10;
	y = num / 10 % 10;
	x = num / 10 / 10;
	if (z == 0 && y != 0) {
		printf("%d%d\n", y, x);
	}else if (z == 0 && y == 0) {
		printf("%d\n", x);
	} else {
		printf("%d%d%d\n", z, y, x);
	}
	return 0;
}