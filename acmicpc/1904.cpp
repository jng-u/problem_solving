/**
 * 백준 1904번
 * 01타일  
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

long long fibo(int n){
    long long n1=0, n2=1;
    long long ans=0;
    if(n==0) return 0;
    else if(n==1) return 1;
    for(int i=2; i<=n; i++){
        ans=n1+n2;
        ans%=15746;
        n1=n2; 
        n2=ans;
    } 
    return ans;
}



int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;

    cout<<fibo(n+1)<<"\n";

    return 0;
}
