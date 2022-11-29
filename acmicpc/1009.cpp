#include <stdio.h>

int main(void){
	int t_case;
	scanf("%d", &t_case);

	for(int i=0; i<t_case; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		int ans=a;
		for(int j=0; j<b-1; j++){
			ans=(ans*a)%10;
		}
		if(ans==0) ans=10;
		printf("%d\n", ans);
	}

	return 0;
}
