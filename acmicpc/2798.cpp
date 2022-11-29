/**
 * 백준 2798번
 * 블랙잭
 * 브루트포스
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin>>N>>M;
    vector<int> cards;
    for(int i=0; i<N; i++){
        int p;
        cin>>p;
        cards.push_back(p);
    }

    int ans=0;
    int sum[N][N][N] = {0, };
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            for(int k=0; k<N; k++){
                if(i==k || j==k) continue;
                int sum = cards[i] + cards[j] + cards[k];
                if(sum<=M && M-sum < M-ans) ans = sum;
            }
        }    
    }
    cout<<ans<<"\n";

    
    return 0;
}
