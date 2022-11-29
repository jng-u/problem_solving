#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void){
	//a~z : 97~122
	string str;
	string key;
	getline(cin, str);
	getline(cin, key);
	
	int str_len=str.size();
	int key_len=key.size();
	for(int i=0; i<str_len; i++){
		if(str[i]!=' '){
			str[i]-=key[i%key_len];
			if(str[i]>0) str[i]+=96;
			else if(str[i]<=0) str[i]+=122;
		}
	}
	cout<<str;
	return 0;
}