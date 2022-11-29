/**
 * 백준 1021번
 * 회전하는 큐 
 * Queue, Deque
 */
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;

    int *loc = new int[M];
    for(int i=0; i<M; i++) cin>>loc[i];

    list<int> l;
    for(int i=0; i<N; i++) l.push_back(i+1);

    int cnt=0;
    for(int i=0; i<M; i++){
        int p = loc[i];
        int idx=0;
        for(int val : l){
            if(val==p) break;
            idx++;
        }
        if(idx < l.size()-idx){
            for(int j=0; j<idx; j++){
                l.push_back(l.front());
                l.pop_front();
                cnt++;
            }
            l.pop_front();
        } else {
            for(int j=0; j<l.size()-idx; j++){
                l.push_front(l.back());
                l.pop_back();
                cnt++;
            }
            l.pop_front();
        }
    }
    cout<<cnt<<"\n";


    return 0;
}