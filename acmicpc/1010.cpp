#include <stdio.h>

int main(){
	int t_case;
	scanf("%d", &t_case);

	for(int i=0; i<t_case; i++){
		int west_count, east_count;
		scanf("%d %d", &west_count, &east_count);

		int answer=1, k=east_count-west_count;
		for(int j=0; j<k; j++){
			answer*=east_count;
			answer/=(j+1);
			east_count--;
		}
		printf("%d\n", answer);
	}
	return 0;
}