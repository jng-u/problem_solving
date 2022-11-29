/**
 * 백준 2748번
 * 피보나치 수 2  
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

long long fibo(int n){
    // if(n==0) return 0;
    // else if(n==1) return 1;
    // else return fibo(n-1)+fibo(n-2);
    long long n1=0, n2=1;
    long long ans=0;
    if(n==0) return 0;
    else if(n==1) return 1;
    for(int i=2; i<=n; i++){
        ans=n1+n2;
        n1=n2; 
        n2=ans;
        // cout<<ans<<"\n";
    } 
    return ans;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    cout<<fibo(n)<<"\n";

    return 0;
}

/*
1 0
0 1
1 1
1 2
2 3
3 5
*/