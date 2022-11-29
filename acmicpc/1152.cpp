#include <stdio.h>
#include <string.h>

int main(void){
	char c;
	int cnt=0;
	bool flag=false;
	while(true){
		//scanf("%c", &c);
		if((c=getchar())==EOF || c=='\n') break;
		if(!flag && c!=' '){ 
			cnt++;
			flag=true;
		} else if(flag && c==' ') flag=false;
	}
	printf("%d", cnt);
	
	return 0;
}