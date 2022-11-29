#include <iostream>
using namespace std;

int main(void){
    int n;			//시험장 개수
    cin>>n;
    
    int *a=new int[n];		//각 시험장별 인원
    for(int i=0; i<n; i++){
	    cin>>a[i];
    }
    
    int b, c;	//총감독관, 부감독관
    cin>>b>>c;

    long long total_sv=n;
    for(int i=0; i<n; i++){
	    int r;
	    if((r=a[i]-b)>0){
	        if(r%c) total_sv+=r/c+1;
	        else if(!(r%c)) total_sv+=r/c;
	    }
    }
    cout<<total_sv;
    
    return 0;
}