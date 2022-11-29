/**
 * 백준 5086번
 * 배수와 약수
 * 정수론과 조합론
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int a, b;
        cin>>a>>b;
        if(a==0 && b==0) break;

        string str;
        if(b%a==0) str="factor";
        else if(a%b==0) str="multiple";
        else str="neither";
        cout<<str<<"\n";
    }
    
    return 0;
}
