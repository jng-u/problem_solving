/**
 * 백준 3036번
 * 링
 * 정수론과 조합론
 */
#include <iostream>
using namespace std;

int gcd(int a, int b){
    return (a%b==0)? b : gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int *R = new int[N];
    for(int i=0; i<N; i++) cin>>R[i];

    for(int i=1; i<N; i++){
        int g = (R[0]>R[i])? gcd(R[0], R[i]) : gcd(R[i], R[0]);
        cout<<R[0]/g<<"/"<<R[i]/g<<"\n";
    }



    return 0;
}
