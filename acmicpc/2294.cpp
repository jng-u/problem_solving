/**
 * 백준 2294번
 * 동전 2
 * Dynamic Programming
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

    int *dp = new int[K+1];
    for(int i=0; i<=K; i++) dp[i] = -1;

    for(int i=0; i<N; i++){
        dp[A[i]] = 1;
        for(int j=A[i]; j<=K; j++){
            if(dp[j-A[i]]<0) continue;
            if(dp[j]<0) dp[j] = dp[j-A[i]]+1;
            else dp[j] = (dp[j] < dp[j-A[i]]+1)? dp[j] : dp[j-A[i]]+1;
        }
    }

    cout<<dp[K]<<"\n";

    return 0;
}
