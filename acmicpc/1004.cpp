#include <stdio.h>

struct Point{
	int x;
	int y;
};

struct Circle{
	int x;
	int y;
	int r;
};

int main(){
	int t_case;
	scanf("%d", &t_case);

	for(int i=0; i<t_case; i++){
		Point s_point, e_point; //start point /end point
		scanf("%d %d %d %d", &s_point.x, &s_point.y, &e_point.x, &e_point.y);
	
		int p_count; //planet count
		scanf("%d", &p_count);
		
		Circle c;
		int count=0;
		for(int j=0; j<p_count; j++){
			scanf("%d %d %d", &c.x, &c.y, &c.r);
			//점 위치 검사
			int s_d_pow = (s_point.x-c.x)*(s_point.x-c.x) + (s_point.y-c.y)*(s_point.y-c.y); //start point-circle distance pow
			int e_d_pow = (e_point.x-c.x)*(e_point.x-c.x) + (e_point.y-c.y)*(e_point.y-c.y); //end point-circle distance pow
			//case 1 : 시작점만 포함
			//case 2 : 끝점만 포함
			if(s_d_pow<c.r*c.r && e_d_pow>c.r*c.r) count++;
			else if(s_d_pow>c.r*c.r && e_d_pow<c.r*c.r) count++;
		}
		printf("%d\n", count);
		count=0;
	}
	return 0;
}