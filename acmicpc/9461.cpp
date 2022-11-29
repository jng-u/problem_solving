/**
 * 백준 9461번
 * 파도반 수열
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

long long pado(int n){
    if(n==1) return 1;
    else if(n==2) return 1;
    else if(n==3) return 1;
    else if(n==4) return 2;
    long long a0=0, a1=1, a2=1;
    for(int i=0; i<n/3; i++){
        a0 = a0+a1;
        a1 = a1+a2;
        a2 = a0+a2;
    }
    long long ans = (n%3==0)? a0 : (n%3==1)? a1 : a2;
    return ans;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;
        cout<<pado(N)<<"\n";
    }

    return 0;
}
