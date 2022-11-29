/**
 * 백준 18258번
 * 큐 2
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

    int q[2000000];
    int front_idx=0;
    int back_idx=0;
    while(N--){
        string order;
        cin>>order;

        if(order=="push"){
            int n;
            cin>>n;
            q[back_idx++] = n;
        } else if(order=="pop"){
            if(back_idx-front_idx==0) {
                cout<<"-1\n";
                continue;
            }
            cout<<q[front_idx++]<<"\n";
        } else if(order=="size"){
            cout<<back_idx-front_idx<<"\n";
        } else if(order=="empty"){
            cout<<(back_idx-front_idx==0)<<"\n";
        } else if(order=="front"){
            if(back_idx-front_idx==0) {
                cout<<"-1\n";
                continue;
            }
            cout<<q[front_idx]<<"\n";
        } else if(order=="back"){
            if(back_idx-front_idx==0) {
                cout<<"-1\n";
                continue;
            }
            cout<<q[back_idx-1]<<"\n";
        }
    }


    return 0;
}
