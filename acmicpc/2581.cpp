/**
 * 백준 2581번
 * 소수
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int M, N;
    cin>>M>>N;

    bool* primes = new bool[N+1];
    for(int i=2; i<N+1; i++) primes[i]=true;
    primes[1] = false;

    for(int i=2; i*i<=N; i++){
        int j=i;
        while(i*j<=N){
            primes[i*j]=false;
            j++;
        }
    }

    // for(int i=0; i<max+1; i++){
    //     cout<<primes[i]<<" ";
    // }
    // cout<<"\n";

    int sum=0;
    int min=0;
    for(int i=M; i<=N; i++){
        if(primes[i]) {
            if(sum==0) min=i;
            sum+=i;
        }
    }
    if(sum==0) cout<<"-1\n";
    else {
        cout<<sum<<"\n";
        cout<<min<<"\n";
    }

    return 0;
}
