/**
 * 백준 1179번
 * 마지막 요세푸스 문제
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long N;
    int K;
    cin>>N>>K;

    int m=1;
    for(int i=2; i*K<=N; i++) m = i;
    // cout<<"m:"<<m<<"\n";
    
    int t=m;
    for(int i=1; i*m<K; i++) t = m*(i+1);

    int r = 0;
    for(int i=1; i<=t; i++){
        r = (r+K) % i;
    }
    // cout<<r<<"\n";

    for(int i=t/m+1; i<=K; i++){
        r = r + r/(K-1);
    }
    // cout<<r<<"\n";

    for(int i=m*K+1; i<=N; i++){
        r = (r+K) % i;
    }
    cout<<r+1<<"\n";
    
    return 0;
}
