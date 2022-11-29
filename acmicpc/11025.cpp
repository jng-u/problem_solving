/**
 * 백준 11025번
 * 요세푸스 문제 3
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    int r = 0;
    for(int i=1; i<=N; i++){
        r = (r+K) % i;
    }
    cout<<r+1<<"\n";
    
    return 0;
}
