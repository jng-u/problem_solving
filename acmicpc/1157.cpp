#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
	char c;
	int a_arr[26]={0,};
	while(true){
		if((c=getchar())==EOF || c=='\n') break;
		if(65<=c && c<=90) c+=32;
		a_arr[(int)(c-97)]++;
	}

	int max=0;
	char ans;
	for(int i=0; i<26; i++) {
		if(a_arr[i]>max){
			max=a_arr[i];
			ans=i+65;
		}
	}
	for(int i=0; i<26; i++) {
		if(i!=ans-65) if(a_arr[i]==max) ans='?';
	}

	cout<<ans;


	return 0;
}