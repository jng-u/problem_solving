/**
 * 백준 10866번
 * 덱
 * Queue, Deque
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int dq[20000];
    int front_idx=9999;
    int back_idx=10000;
    while(N--){
        string order;
        cin>>order;

        if(order=="push_front"){
            int n;
            cin>>n;
            dq[front_idx--] = n;
        } else if(order=="push_back"){
            int n;
            cin>>n;
            dq[back_idx++] = n;
        } else if(order=="pop_front"){
            if(back_idx-front_idx==1) {
                cout<<"-1\n";
                continue;
            }
            cout<<dq[++front_idx]<<"\n";
        } else if(order=="pop_back"){
            if(back_idx-front_idx==1) {
                cout<<"-1\n";
                continue;
            }
            cout<<dq[--back_idx]<<"\n";
        } else if(order=="size"){
            cout<<back_idx-front_idx-1<<"\n";
        } else if(order=="empty"){
            cout<<(back_idx-front_idx==1)<<"\n";
        } else if(order=="front"){
            if(back_idx-front_idx==1) {
                cout<<"-1\n";
                continue;
            }
            cout<<dq[front_idx+1]<<"\n";
        } else if(order=="back"){
            if(back_idx-front_idx==1) {
                cout<<"-1\n";
                continue;
            }
            cout<<dq[back_idx-1]<<"\n";
        }
    }


    return 0;
}