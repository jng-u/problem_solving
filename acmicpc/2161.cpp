/**
 * 백준 2161번
 * 카드1
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
    for(int i=1; i<=N; i++) q.push(i);

    while(q.size() != 1){
        cout<<q.front()<<" ";
        q.pop();

        q.push(q.front());
        q.pop();
    }
    cout<<q.front()<<"\n";

    return 0;
}
