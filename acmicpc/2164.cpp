/**
 * 백준 11866번
 * 요세푸스 문제 0
 * Queue, Deque
 */
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    
    queue<int> q;
    for(int i=0; i<N; i++) q.push(i+1);

    while(q.size() > 1){
        q.pop();

        int p = q.front();
        q.pop();
        q.push(p);
    }

    cout<<q.front()<<"\n";


    return 0;
}
