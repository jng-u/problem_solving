/**
 * 백준 19945번
 * 새로운 언어 CC 
 * 2020 IGRUS Newbie Programming Contest B번
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    if(n<0) cout<<"32\n";
    else if(n==0) cout<<"1\n";
    else {
        int t = 1;
        int cnt=0;
        n++;
        while(t < n){
            cnt++;
            t*=2;
        }
        cout<<cnt<<"\n";
    }

    return 0;
}
