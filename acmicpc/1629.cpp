/**
 * 백준 1629번
 * 곱셈
 * divide & conquer
 */
#include <iostream>
using namespace std;

long long mul(long long A, long long B, long long C){
    if(B==1) return A;
    if(B==0) return 1;
    long long a = mul(A, B/2, C)%C;
    a = (a*a)%C;
    if(B%2==0) return a;
    else return (a*A)%C;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long A, B, C;
    cin>>A>>B>>C;

    if(A>C) A %= C;

    long long ans = mul(A, B, C);
    cout<<ans<<"\n";
    
    return 0;
}
