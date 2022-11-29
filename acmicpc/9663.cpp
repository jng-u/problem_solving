/**
 * 백준 9663번
 * N-Queen
 * Back Tracking
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int cnt=0;

void visit(int level, vector<int> order, int n){
    if(level==n){
        cnt++;
        return ;
    }
    for(int i=0; i<n; i++){
        bool flag=false;
        for(int j=0; j<order.size(); j++){
            if(i==order[j] || abs(i-order[j])==abs(level-j)) {
                flag=true;
                break;
            }
        }
        if(flag) continue;
        vector<int> ordercopy = vector<int>(order);
        ordercopy.push_back(i);
        visit(level+1, ordercopy, n);
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    vector<int> order;
    visit(0, order, N);

    cout<<cnt<<"\n";

    return 0;
}