/**
 * 백준 1436번
 * 영화감독 숌
 * 브루트포스
 */

#include <iostream>
using namespace std;

bool check666(int n){
    int cnt=0;
    
    while(true){
        if(n%10 == 6) {
            cnt++;
            if(cnt==3) break;
        }
        else if(cnt!=0) cnt=0;

        n/=10;
        if(n==0) break;
    }
    if(cnt==3) return true;
    else return false;
}


int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    
    int cnt=0;
    for(int i=666; ; i++){
        if(check666(i)) cnt++;
        if(cnt==N){
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}
