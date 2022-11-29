/**
 * 백준 7568번
 * 덩치
 * 브루트포스
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    
    int *heights = new int[N];
    int *weights = new int[N];
    for(int i=0; i<N; i++){
        int h, w;
        cin>>h>>w;
        heights[i] = h;
        weights[i] = w;
    }

    for(int i=0; i<N; i++){
        int cnt=1;
        int h = heights[i];
        int w = weights[i];
        for(int j=0; j<N; j++){
            if(i==j) continue;
            if(h < heights[j] && w < weights[j]) cnt++;
        }
        cout<<cnt<<" ";
    }
    cout<<"\n";
    
    return 0;
}
