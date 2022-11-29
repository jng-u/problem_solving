/**
 * 백준 2004번
 * 조합 0의 개수
 * 정수론과 조합론
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;

    int cnt=0;
    int cnt2=0;
    
    int p=5;
    while(p <= N){
        cnt += N/p;
        cnt -= M/p;
        cnt -= (N-M)/p;
        if(p > 400000000) break;
        p*=5;
    }

    p=2;
    while(p <= N){
        cnt2 += N/p;
        cnt2 -= M/p;
        cnt2 -= (N-M)/p;
        if(p > 1000000000) break;
        p*=2;
    }
    
    cout<<min(cnt, cnt2)<<"\n";
    // cout<<cnt<<"\n";

    return 0;
}
