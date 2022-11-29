/**
 * 백준 1912번
 * 평범한 배낭 (knapsack problem)
 * Dynamic Programming
 */
#include <iostream>
#include <string>
using namespace std;

void bitonic(int *arr, int *arr2, int s, int e){
    int len = e-s;
    if(len<2) return ;
    int m = (s+e)/2;
    bitonic(arr, arr2, s, m);
    bitonic(arr, arr2, m, e);
    int *tmp = new int[len];
    int *tmp2 = new int[len];
    int idx=0;
    int f=s, b=m;
    while(true){
        if(arr[f]<arr[b]){
            tmp2[idx] = arr2[f];
            tmp[idx++] = arr[f++];
        } else if(arr[f]>arr[b]) {
            tmp2[idx] = arr2[b];
            tmp[idx++] = arr[b++];    
        } else {
            if(arr2[f]<arr2[b]){
                tmp2[idx] = arr2[f];
                tmp[idx++] = arr[f++];
            } else {
                tmp2[idx] = arr2[b];
                tmp[idx++] = arr[b++];  
            }
        }

        if(f>=m){
            while(b<e){
                tmp2[idx] = arr2[b];
                tmp[idx++] = arr[b++];
            }    
            break;
        } else if(b>=e) {
            while(f<m){
                tmp2[idx] = arr2[f];
                tmp[idx++] = arr[f++];
            }    
            break;
        }
    }
    for(int i=0; i<len; i++){
        arr[s+i] = tmp[i];
        arr2[s+i] = tmp2[i];
    }
}

int *W;
int *V;

// int P(int n, int wei){
//     if(n==0) return 0;
//     else if(wei<=0) return 0;
//     else if(wei-W[n-1]<0) return P(n-1, wei);
//     return max(P(n-1, wei), V[n-1] + P(n-1, wei-W[n-1]));
// }

int P(int n, int wei){
    if(n==0) return 0;
    else if(wei<=0) return 0;
    else if(wei-W[n-1]<0) return P(n-1, wei);
    return max(P(n-1, wei), V[n-1] + P(n-1, wei-W[n-1]));
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;

    W = new int[N];
    V = new int[N];
    for(int i=0; i<N; i++) cin>>W[i]>>V[i];

    bitonic(W, V, 0, N);

    // int idx=N-1;
    // while(W[idx] > K) idx--;
    
    // int ans = P(idx+1, K);
    // cout<<ans<<"\n";
    
    // int values[101][100001] = {0, };
    int values[101][100001] = {0, };
    for(int i=W[0]; i<=K; i++){
        values[1][i] = V[0];
    }
    for(int i=2; i<=N; i++){
        for(int j=W[0]; j<=K; j++){
            if(j-W[i-1]<0) values[i][j] = values[i-1][j];
            else values[i][j] = max(values[i-1][j], V[i-1] + values[i-1][j-W[i-1]]);
        }
    }

    cout<<values[N][K]<<"\n";

    return 0;
}
