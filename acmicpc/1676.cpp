/**
 * 백준 1676번
 * 팩토리얼 0의 개수
 * 정수론과 조합론
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;

    int cnt=0;

    for(int i=1; i<=N; i++){
        int p=i;
        while(p%5==0){
            cnt++;
            p/=5;
        }
    }
    
    cout<<cnt<<"\n";

    return 0;
}
