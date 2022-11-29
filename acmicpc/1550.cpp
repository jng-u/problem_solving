#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
	char c;
	int arr[6], cnt=0;
	
	while(true){
		c=getchar();
		if(c==EOF || c=='\n') break;
		if(48<=c && c<=57) arr[cnt]=(int)(c-48);
		else if(65<=c && c<=70) arr[cnt]=(int)(c-55);
		cnt++;
	}

	int sum=0;
	for(int i=0; i<cnt; i++){
		for(int j=0; j<cnt-1-i; j++) arr[i]*=16;
		sum+=arr[i];
	}

	cout<<sum;

	return 0;
}