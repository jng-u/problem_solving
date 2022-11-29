#include <stdio.h>

int main(){
	int t_case;
	scanf("%d", &t_case);

	for(int i=0; i<t_case; i++){
		int b_count, r_count; //building count, rule count
		scanf("%d %d", &b_count, &r_count);

		int delay[b_count];
		for(int j=0; j<b_count; j++) scanf("%d", &delay[j]);

		int b_order[r_count][2];
		for(int j=0; j<r_count; j++) scanf("%d %d", &b_order[j][0], &b_order[j][1]);

		
	}
	return 0;
}