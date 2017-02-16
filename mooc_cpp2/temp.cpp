#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	
	*/
	int a[] = {1,2,3,4,5,};
	int *p = a;
	int *q = &a[5];
	printf("%ld", q-p);
	return 0;
}