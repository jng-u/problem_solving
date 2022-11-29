#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);

	int ans=0;
	if(num<100) ans=num;
	else {
		for(int i=100; i<=num; i++){
			int a = i/100;
			int b = (i%100)/10;
			int c = i%10;
			if(b-a==c-b) ans++;
		}
		ans+=99;	
	}

	printf("%d", ans);

	return 0;
}