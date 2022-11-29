/**
 * 백준 1966번
 * 프린터 큐
 * Queue, Deque
 */
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        int *p = new int[N];
        for(int i=0; i<N; i++) cin>>p[i];
        
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int i=0; i<N; i++) {
            q.push(make_pair(i, p[i]));
            pq.push(p[i]);
        }
        
        int n;
        do {
            int max = pq.top();
            while(max > q.front().second){
                q.push(q.front());
                q.pop();
            }
            n = q.front().first;
            q.pop();    
            pq.pop();
        } while(n != M);

        cout<<N-q.size()<<"\n";
    }


    return 0;
}
