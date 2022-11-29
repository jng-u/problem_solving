#include <stdio.h>

int main(void){
	int a, b;
	scanf("%d %d", &a, &b);

	if((long long)a-(long long)b<0) printf("%lld", (long long)b-(long long)a);
	else printf("%lld", (long long)a-(long long)b);

	return 0;
}
