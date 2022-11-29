/**
 * 백준 1874번
 * 스택 수열
 * Stack
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    stack<int> s;
    vector<char> str;

    int cnt=1;
    s.push(cnt++);
    str.push_back('+');
    bool flag = true;
    for(int i=0; i<N; i++){
        int n;
        cin>>n;
        while(cnt<=n) {
            s.push(cnt++);
            str.push_back('+');
        }
        if(s.top() == n) {
            s.pop();
            str.push_back('-');
        } else {
            flag = false;
        }
    }

    if(flag)
        for(int i=0; i<str.size(); i++) cout<<str[i]<<"\n";
    else cout<<"NO\n";


    return 0;
}
