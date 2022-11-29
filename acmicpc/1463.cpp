/**
 * 백준 1463번
 * 1로 만들기
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	int N;
	cin>>N;
    
    // int count[1000001] = {0, };
    int *count = new int [1000001];
    for(int i=N; i>0; i--) count[i]=0;
    for(int i=N-1; i>0; i--){
        int minc=count[i+1];
        if(i*2 <= N) minc = (minc < count[i*2])? minc : count[i*2];
        if(i*3 <= N) minc = (minc < count[i*3])? minc : count[i*3];
        count[i] = minc+1;
    }
    
    cout<<count[1]<<"\n";

    return 0;
}
