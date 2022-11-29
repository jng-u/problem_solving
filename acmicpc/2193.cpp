#include <iostream>
using namespace std;

int ans=1;

unsigned long long fibonacci(int n);
//void ichin(int bin);

int main(void){
	int n;
	cin>>n;
	cout<<fibonacci(n);
	return 0;
}

unsigned long long fibonacci(int n){
	unsigned long long f_arr[3]={0, 1, 0};
	for(int i=0; i<n; i++){
		f_arr[0]=f_arr[1];
		f_arr[1]=f_arr[2];
		f_arr[2]=f_arr[0]+f_arr[1];
	}
	return f_arr[2];
}
/*
void ichin(int bin){
	if(bin==0){
		ans++;
		ichin(0);
		ichin(1);
	} else if(bin==1){
		ichin(0);
	}
}
*/