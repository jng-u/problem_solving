#include <stdio.h>

int count=1;
int tournament(int num1, int num2);

int main(){
	int p_num; //participants_number
	int kim_num, lim_num; //김지민, 임한수 번호
	scanf("%d %d %d", &p_num, &kim_num, &lim_num);
	
	kim_num -= 1;	//0번 부터 인덱싱 하기 위해서
	lim_num -= 1;

	printf("%d", tournament(kim_num, lim_num));
	return 0;
}

int tournament(int num1, int num2){
	num1 /= 2;
	num2 /= 2;
	if(num1==num2) return count;
	else if(num1!=num2){
		count++;
		return tournament(num1, num2);
	} 
}