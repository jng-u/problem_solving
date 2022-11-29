/**
 * 백준 10989번
 * 수 정렬하기 3
 * 카운팅 정렬
 */

#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int count[10001] = {0, };
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int n;
        cin>>n;
        count[n]++;
    }

    for(int i=1; i<=10000; i++){
        while(count[i]--){
            cout<<i<<"\n";
        }
    }
    
    return 0;
}
