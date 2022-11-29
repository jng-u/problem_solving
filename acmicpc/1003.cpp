#include <stdio.h>

int zero_count=0, one_count=0;

int fibonacci(int n) {
    if (n==0) {
    	zero_count++;
        return 0;
    } else if (n==1) {
        one_count++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
	int t_case;
	scanf("%d", &t_case);

	int tmp;
	for(int i=0; i<t_case; i++){
		scanf("%d", &tmp);
		fibonacci(tmp);
		printf("%d %d\n", zero_count, one_count);
		zero_count = one_count = 0;
	}

	return 0;
}