#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	int isPrime=1;//是否是质数的标志
	int s=(int)sqrt(n);//对n开根号
	for(int i=s;i>1;i--){//n除以每个比n开根号小比1大的自然数
	    if(n%i==0){//如果有能被整除的，则不是质数
	        isPrime=0;
	    }
	}
	return isPrime;
}
int main(int argc, char const *argv[])
{
	int n, m;
	int total = 0, res = 0;
	scanf("%d %d", &n, &m);
	for (int count=0, i=2; count < m; i++){
		if (isPrime(i)) {
			// sushu 
			// printf("%d\n", i);
			count++;
			// printf("%d\n", count);
			if (count == n) {
				res = total;
				// printf("res = %d\n", res);
			}
			total += i;
			// printf("total = %d\n", total);
		}
		
	}
	printf("%d\n", total - res);
	return 0;
}