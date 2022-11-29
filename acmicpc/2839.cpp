#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);

	int ans=-1;
	for(int i=0; i<=num/3; i++){
		if((num-3*i)%5==0){
			ans=i;
			ans+=(num-3*i)/5;
			break;
		}
	}
	printf("%d", ans);

	return 0;
}