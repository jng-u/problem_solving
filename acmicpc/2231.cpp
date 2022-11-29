/**
 * 백준 2231번
 * 분해합
 * 브루트포스
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin>>N;

    int digit=1;
    for(int i=10; ; i*=10){
        if(N/i==0) break;
        digit++;
    }

    int ans=0;
    for(int i=N-1; i>=N-9*digit; i--){
        int sum = i;
        
        int p=1;
        for(int j=0; j<digit-1; j++){
            p*=10;
        }
        
        int tmp=i;
        while(p!=0){
            sum+=tmp/p;
            tmp=tmp%p;
            p/=10;
        }

        if(sum==N) ans=i;
    }

    cout<<ans<<"\n";
    
    return 0;
}
