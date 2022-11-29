#include <stdio.h>

int main(){
	int x1, y1, x2, y2, r1, r2, tCase, count=0, distance_pow;
	
	scanf("%d", &tCase);
	
	for(int i=0; i<tCase; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		if(x1==x2 && y1==y2 && r1==r2){
			count=-1;
		} else{
			distance_pow = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); 
			if(distance_pow > (r1+r2)*(r1+r2)) count=0;
			if(distance_pow == (r1+r2)*(r1+r2)) count=1;
			if(distance_pow < (r1+r2)*(r1+r2)) count=2;
			if(distance_pow == (r1-r2)*(r1-r2))	count=1;
			if(distance_pow < (r1-r2)*(r1-r2)) count=0;
		}
		printf("%d\n", count);
		count=0;
	}
	return 0;
}
