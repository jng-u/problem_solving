#include <stdio.h>

int main(){
	int t_case;
	scanf("%d", &t_case);

	for(int i=0; i<t_case; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		int distance = end-start;

		int count=0, ans=0;
		for(int j=1; j<=distance; j++){
			count += j;
			ans++;
			if(count>=distance-1){
				ans+=1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}