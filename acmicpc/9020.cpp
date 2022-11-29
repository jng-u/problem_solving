/**
 * 백준 9020번
 * 골드바흐의 추측
 * 소수 응용
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    vector<int> numbers;
    int max=0;
    while(N--){
        int p;
        cin>>p;
        numbers.push_back(p);
        if(p > max) max=p;
    }

    bool* primes = new bool[max+1];
    for(int i=2; i<max+1; i++) primes[i]=true;
    primes[1] = false;

    for(int i=2; i*i<=max; i++){
        int j=i;
        while(i*j<=max){
            primes[i*j]=false;
            j++;
        }
    }

    // for(int i=0; i<max+1; i++){
    //     cout<<primes[i]<<" ";
    // }
    // cout<<"\n";

    for(int i=0; i<numbers.size(); i++){
        int p, q;
        p = q = numbers[i]/2;
        while(!(primes[p] && primes[q])){
            p--; q++;
        }
        cout<<p<<" "<<q<<"\n";
    }
    
    return 0;
}
