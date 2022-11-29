/**
 * 백준 4949번
 * 균형잡힌 세상
 * Stack
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    while(true){
        getline(cin, str);
        if(str == ".") break;

        char stack[100];
        int idx=0;

        bool flag=true;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='(' || str[i]=='[') stack[idx++] = str[i];
            else if(str[i]==')' || str[i]==']'){
                if(idx==0 || 
                    ((str[i]==')' && stack[idx-1] != '(')) || 
                    ((str[i]==']' && stack[idx-1] != '['))) {
                    flag = false;
                    break;
                } else {
                    idx--;
                }
            }
        }
        if(idx!=0) flag = false;

        if(flag) cout<<"yes\n";
        else cout<<"no\n";
    }

    return 0;
}
