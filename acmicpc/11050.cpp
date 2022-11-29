/**
 * 백준 11050번
 * 이항 계수 1
 * 정수론과 조합론
 */
#include <iostream>
using namespace std;

int facto(int n){
    int ans=1;
    for(int i=1; i<=n; i++) ans *= i;
    return ans;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    cout<<facto(N)/(facto(K)*facto(N-K))<<"\n";

    return 0;
}
