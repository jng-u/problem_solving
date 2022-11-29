#include <stdio.h>

//촤소공배수 구하기 / 유클리드 호제법
int get_gcd(int n1, int n2);

int main(void){
	int t_case;
	scanf("%d", &t_case);

	for(int t=0; t<t_case; t++){
		int n1, n2;
		scanf("%d %d", &n1, &n2);

		printf("%d\n", n1*n2/get_gcd(n1, n2));
	}

	return 0;
}

int get_gcd(int n1, int n2){
	int max, min;
	if(n1>n2) max=n1, min=n2;
	else max=n2, min=n1;
	
	if(n1%n2==0) return n2;
	else return get_gcd(n2, n1%n2);
}
