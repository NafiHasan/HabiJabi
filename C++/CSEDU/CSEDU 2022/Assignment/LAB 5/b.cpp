#include <stdio.h>  

int main()
{
 	long long n;
 	scanf("%lld",&n);
 	for (long long i=1; i<=n; i++){
 		printf("%lld! = ",i);
 		long long fact=1;
 		for (long long j=1; j<=i; j++){
 			printf("%lld ",j);
 			if (j<i)printf("x ");
 			fact*=j;
 		}
 		printf("= %lld\n",fact);
 	}
    return 0;
}