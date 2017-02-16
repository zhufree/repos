#include <stdio.h>

int main(int argc, char const *argv[])
{
	int bjt, utc, hour, minute;
	scanf("%d", &bjt);
	hour = bjt / 100;
	minute = bjt % 100;
	// printf("%d %d\n", hour, minute);
	if (hour >= 8) {
		utc = (hour - 8) * 100 + minute;
	} else {
		utc = (24 - 8+hour) * 100 + minute;
	}
	printf("%d\n", utc);
	return 0;
}