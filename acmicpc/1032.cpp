#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void){
	int n;
	cin>>n;
	fflush(stdin);

	string pre_st;
	for(int i=0; i<n; i++){
		string str;
		if(i==n-1)cin>>str;
		else getline(cin, str, '\n');
		if(i>0){
			for(int i=0; i<pre_str.size(); i++){
				if(pre_str.at(i) != str.at(i)) str.at(i)='?';
			}
		}
		pre_str=str;
	}
	cout<<pre_str;

	return 0;
}