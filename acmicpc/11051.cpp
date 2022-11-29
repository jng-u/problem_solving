/**
 * 백준 11051번
 * 이항 계수 2
 * 정수론과 조합론
 */
#include <iostream>
#include <vector>
using namespace std;

int nCr(int n, int r){
    int s = (r>n/2)? r : (n-r);

    int *p = new int[n-s+1]; 
    for(int i=1; i<=n-s; i++) p[i] = 1; 
    
    int ans=1;
    vector<int> val;
    for(int i=s+1; i<=n; i++) {
        ans *= i;
        for(int j=n-s; j>0; j--) {
            if(p[j]>0 && ans%j==0) {
                ans /= j;
                p[j]--;
                if(p[j]>0) j++;
            } else if(p[j]>0) {
                for(int k=2; k<=j; k++){
                    if(j%k==0 && ans%k==0) {
                        ans /= k;
                        p[j/k]++;
                        p[j]--;
                        break;
                    }        
                }
            }
        }
        if(ans > 10007){
            ans %= 10007;
            val.push_back(ans);
            ans = 1;
        }
    }

    for(int i=0; i<val.size(); i++) {
        ans *= val[i];
        ans %= 10007;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    // cout<<nCr(N, K)<<"\n";

    int dp[1001][1001] = {0, };
    for(int i=0; i<=N; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
        }
    }
    
    cout<<dp[N][K]<<"\n";

    return 0;
}
