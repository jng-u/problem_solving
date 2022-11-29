/**
 * 백준 4948번
 * 베르트랑 공준
 * 소수 응용
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    vector<int> numbers;
    int max=0;
    while(true){
        cin>>N;
        if(N==0) break;
        numbers.push_back(N);
        if(N > max) max=N;
    }

    max*=2;
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
        int cnt=0;
        for(int j=numbers[i]+1; j<=numbers[i]*2; j++){
            if(primes[j]) cnt++;
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}
