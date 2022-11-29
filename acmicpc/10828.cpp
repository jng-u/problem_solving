/**
 * 백준 10828번
 * 스택
 * Stack
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int stack[10000];
    int idx=0;
    while(N--){
        string command;
        cin>>command;
        if(command == "push"){
            int data;
            cin>>data;
            stack[idx++] = data;
        } else if(command == "pop"){
            if(idx == 0){
                cout<<"-1\n";
                continue;
            }
            idx--;
            cout<<stack[idx]<<"\n";
        } else if(command == "size"){
            cout<<idx<<"\n";
        } else if(command == "empty"){
            cout<<((idx==0)? "1" : "0")<<"\n";
        } else if(command == "top"){
            if(idx == 0){
                cout<<"-1\n";
                continue;
            }
            cout<<stack[idx-1]<<"\n";
        }
    }

    return 0;
}
