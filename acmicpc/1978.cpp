/**
 * 백준 1978번
 * 소수 찾기
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

    int cnt=0;
    for(int i=0; i<numbers.size(); i++){
        if(primes[numbers[i]]) cnt++;
    }
    cout<<cnt<<"\n";
    
    return 0;
}
