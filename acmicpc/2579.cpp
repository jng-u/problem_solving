/**
 * 백준 2579번
 * 계단 오르기
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
    
    int scores[301] = {0, };
    for(int i=1; i<N+1; i++) cin>>scores[i];

    int acum[301][2] = {0, };               //acum[i][0] : 한칸이동해 i에 도착 //acum[i][1] : 두칸이동해 i에 도착
    for(int i=1; i<N+1; i++){
        if(i==2) acum[i][0] = scores[i] + acum[i-1][0];
        else acum[i][0] = scores[i] + acum[i-1][1];
        if(i>1)
            acum[i][1] = scores[i] + ((acum[i-2][0] > acum[i-2][1])? acum[i-2][0] : acum[i-2][1]);
        // cout<<acum[i][0]<<" "<<acum[i][1]<<"\n";
    }

    int max = (acum[N][0] > acum[N][1])? acum[N][0] : acum[N][1];
    cout<<max<<"\n";

    return 0;
}
