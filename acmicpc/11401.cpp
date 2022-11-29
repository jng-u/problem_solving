/**
 * 백준 11401번
 * 이항 계수 3
 * divide & conquer
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    int dp[4000001][4000001];
    for(int i=1; i<=N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=1; j<=K; j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%1000000007;
        }
    }
    cout<<dp[N][K]<<"\n";
    
    return 0;
}
