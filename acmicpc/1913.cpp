#include <stdio.h>

int main(void){
	int n;						//배열 사이즈
	scanf("%d", &n);
	int point;
	scanf("%d", &point);

	int snail[100][100] = {};	//100x100 사이즈 배열의 초기값을 0으로 초기화
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			snail[i][j]=-1;		//입력받은 사이즈크기반큼의 배열의 값을 -1로만듬
		}
	}

	int cnt=n*n;				//배열에 넣어줄 값
	int x=0, y=0;				//시작점
	int ax, ay;	
	while(cnt>1){
		while(snail[y+1][x]==-1){		
			snail[y][x]=cnt;	//↓
			if(cnt==point) ax=x, ay=y;
			cnt--;
			y++;
		}
		while(snail[y][x+1]==-1){
			snail[y][x]=cnt;	//→
			if(cnt==point) ax=x, ay=y;
			cnt--;
			x++;
		}
		while(snail[y-1][x]==-1){
			snail[y][x]=cnt;	//↑
			if(cnt==point) ax=x, ay=y;
			cnt--;
			y--;
		}
		while(snail[y][x-1]==-1){
			snail[y][x]=cnt;	//←
			if(cnt==point) ax=x, ay=y;
			cnt--;
			x--;
		}
	}
	snail[y][x]=1;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%3d ", snail[i][j]);
		}
		printf("\n\n");
	}
	printf("%d %d", ay+1, ax+1);

	return 0;
}
