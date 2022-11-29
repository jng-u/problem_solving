/**
 * 백준 15652번
 * N과 M (4)
 * Back Tracking
 */
#include <iostream>
#include <vector>
using namespace std;

void visit(int level, vector<int> order, int n, int m){
    if(level==m){
        for(int i=0; i<order.size(); i++){
            cout<<order[i]+1<<" ";
        }
        cout<<"\n";
        return ;
    }
    int ln = (order.empty())? 0 : order[order.size()-1];
    for(int i=ln; i<n; i++){
        vector<int> ordercopy = vector<int>(order);
        ordercopy.push_back(i);
        visit(level+1, ordercopy, n, m);
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;

    vector<int> order;
    visit(0, order, N, M);

    return 0;
}