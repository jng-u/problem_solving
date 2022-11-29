/**
 * 백준 11047번
 * 동전 0
 * 그리디 알고리즘
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    int *A = new int[N];
    for(int i=0; i<N; i++) cin>>A[i];

    int cnt=0;
    int idx = N-1;
    while(K!=0){
        if(A[idx] > K){
            idx--;
            continue;
        }
        cnt += K/A[idx];
        K %= A[idx];
    }

    cout<<cnt<<"\n";

    return 0;
}
