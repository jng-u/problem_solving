/**
 * 백준 11653번
 * 소인수분해
 * 정수론과 조합론
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    
    while(N!=1){
        int pr = 2;
        while(N%pr != 0) pr++;
        N /= pr;
        cout<<pr<<"\n";
    }    
    
    return 0;
}
