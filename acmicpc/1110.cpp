#include <stdio.h>

int prime_num;
int count=0;
int plus_cycle(int num);

int main(){

	scanf("%d", &prime_num);
	printf("%d\n", plus_cycle(prime_num));
	return 0;
}

int plus_cycle(int num){
	if(count!=0 && num == prime_num) return count;
	int f_num, s_num, r_num;	//first_number, second_number, result_number
	f_num = num/10;
	s_num = num%10;
	r_num = (f_num+s_num)%10;
	count++;
	return plus_cycle(s_num*10 + r_num);
}
