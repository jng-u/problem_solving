#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void){
	//2진수->8진수
	/*char bi_n;
	int bi_arr[3]={0}, ei_n[100];
	int cnt=0, cnt2=0;
	while(true){
		bi_n=getchar();
		if(bi_n==EOF || bi_n=='\n') break;
		bi_arr[cnt]=(int)(bi_n-'0');
		cnt++;
		if(cnt%3==0){
			ei_n[cnt2]=bi_arr[0]*4 + bi_arr[1]*2 + bi_arr[2];
			cnt=0;
			cnt2++;
		}
	}
	for(int i=0; i<cnt2; i++){
		cout<<ei_n[i];
	}*/
	int ei_n[333334][3]={0, }, row=0, col=2;
	string bi_n;
	cin>>bi_n;
	for(int i=bi_n.size()-1; i>=0; i--){
		if(col<0){
			row++;
			col=2;
		}
		ei_n[row][col]=(int)(bi_n.at(i)-'0');
		col--;
	}
	for(int i=row; i>=0; i--){
		cout<<ei_n[i][0]*4+ei_n[i][1]*2+ei_n[i][2]*1;
	}

	return 0;
}