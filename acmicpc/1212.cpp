#include <stdio.h>
#include <string>

int trans(int en);

int main(void){
	int arr[333334]={0, };
	
	char eight_n;
	int cnt=0;
	while(true){
		eight_n=getchar();
		if(eight_n==EOF || eight_n=='\n') break;
		
		arr[cnt]=trans((int)(eight_n-48));
		cnt++;
	}

	for(int i=0; i<cnt; i++) {
		if(i!=0){
			if(arr[i]/10==0) printf("00");
			else if(arr[i]/100==0) printf("0");
		}
		printf("%d", arr[i]);
	}

	return 0;
}

int trans(int en){
	switch(en){
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 10;
	case 3:
		return 11;
	case 4:
		return 100;
	case 5:
		return 101;
	case 6:
		return 110;
	case 7:
		return 111;
	}
}