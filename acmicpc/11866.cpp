/**
 * 백준 11866번
 * 요세푸스 문제 0
 * Queue, Deque
 */
#include <iostream>
#include <queue>
using namespace std;

struct  node {
    int data;
    node *prev;
    node *next;
};

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;
    
    queue<int> q;
    for(int i=1; i<=N; i++) q.push(i);

    cout<<"<";
    while(!q.empty()){
        for(int i=0; i<K-1; i++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();
        if(q.empty()) break;
        cout<<", ";
    }
    cout<<">\n";

    // node *head = new node;
    // node *p = head;
    // for(int i=1; i<N; i++){
    //     p->data = i;
    //     p->next = new node;
    //     p->next->prev = p;
    //     p = p->next;
    // }
    // p->data = N;
    // p->next = head;
    // head->prev = p;

    // cout<<"<";
    // p = head;
    // while(p->next != p){
    //     for(int i=0; i<K-1; i++){
    //         p = p->next;
    //     }
    //     node *r = p;
    //     r->prev->next = r->next;
    //     r->next->prev = r->prev;
    //     cout<<r->data<<", ";
    //     p = p->next;
    //     delete r;
    // }
    // cout<<p->data<<">\n";

    return 0;
}