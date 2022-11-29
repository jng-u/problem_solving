/**
 * 백준 2293번
 * 동전 1
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

// void P(int *A, int idx, int K){
// 	if(K==0) {
// 		cnt++;
// 		return ;
// 	} else if(K<0){
// 		return ;
// 	}
// 	for(int i=0; i<=idx; i++){
// 		P(A, i, K-A[i]);
// 	}
// }

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    int *A = new int[N];
    for(int i=0; i<N; i++) cin>>A[i];

	// int dp[100][10001] = {0, };
	// int **dp = new int*[N];
	// for(int i=0; i<N; i++) dp[i] = new int[K+1];
	// for(int i=0; i<N; i++)
	// 	for(int j=0; j<K; j++) dp[i][j] = 0;

	// for(int i=0; i<N; i++){
	// 	if(A[i] > K) break;
	// 	dp[i][A[i]] = 1;
	// }

	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<=i; j++){
	// 		for(int kk=A[i]; kk<=K; kk++){
	// 			dp[i][kk] += dp[j][kk-A[i]];
	// 		}
	// 	}
	// }

	// int ans=0;
	// for(int i=0; i<N; i++) ans+=dp[i][K];

	unsigned int dp[10001] = {0, };

	for(int i=0; i<N; i++){
		if(A[i]>K) continue;
		dp[A[i]]++;
		for(int j=A[i]; j<=K; j++){
			dp[j] += dp[j-A[i]];
		}
	}
	
	cout<<dp[K]<<"\n";

    return 0;
}
