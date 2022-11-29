/**
 * 백준 9012번
 * 괄호
 * Stack
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int cnt=0;

        string str;
        cin>>str;

        bool flag=true;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '('){
                cnt++; 
            } else if(str[i] == ')'){
                if(cnt==0){
                    flag = false;
                    break;
                }
                cnt--;
            }
        }
        if(cnt!=0) flag = false;

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
