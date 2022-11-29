/**
 * 백준 1912번
 * 연속합
 * Dynamic Programming
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;

    int *A = new int[N];
    for(int i=0; i<N; i++) cin>>A[i];

    int ans = A[0];
    int *sum = new int[N];
    sum[0] = A[0];
    for(int i=1; i<N; i++){
        sum[i] = (0 > sum[i-1])? A[i] : sum[i-1]+A[i];
        ans = (ans > sum[i])? ans : sum[i];
    }
    
    // for(int i=0; i<N; i++) cout<<sum[i]<<" ";
    cout<<ans<<"\n";
    
    return 0;
}
