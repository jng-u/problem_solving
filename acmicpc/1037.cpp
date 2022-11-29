#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);

	int measure[num];
	for(int i=0; i<num; i++) scanf("%d", &measure[i]);

	int max=measure[0], min=measure[0];
	for(int i=1; i<num; i++){
		if(measure[i]>max) max=measure[i];
		if(measure[i]<min) min=measure[i];
	}
	
	printf("%d", max*min);

	return 0;
}