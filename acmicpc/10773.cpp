/**
 * 백준 10773번
 * 제로
 * Stack
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int K;
    cin>>K;

    int stack[100000];
    int idx=0;
    while(K--){
        int data;
        cin>>data;
        if(data==0) idx--;
        else stack[idx++] = data;
    }

    int ans = 0;
    for(int i=0; i<idx; i++) ans += stack[i];

    cout<<ans<<"\n";

    return 0;
}
