/**
 * 백준 1541번
 * 잃어버린 괄호
 * 그리디 알고리즘
 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    cin>>str;

    int n[50];
    char op[50];
    int idx=0;
    while(true){
        int i=0;
        while(str[i] != '-' && str[i] != '+' && i<str.size()) i++;
        if(i==str.size()) {
            n[idx] = atoi(str.c_str());
            break;
        }
        n[idx] = atoi(str.substr(0, i).c_str());
        op[idx] = str[i];
        idx++;
        str = str.substr(i+1);
    }

    int ans = n[0];
    for(int i=0; i<idx; i++){
        if(op[i]=='-'){
            int tmp=0;
            while(true){
                tmp+=n[i+1];
                i++;
                if(op[i]=='-' || i==idx){
                    i--;
                    ans -= tmp;
                    break;
                } 
            }
        }else {
            ans += n[i+1];
        }
    }

    cout<<ans<<"\n";
    
    return 0;
}
