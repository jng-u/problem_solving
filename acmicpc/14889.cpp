#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int **S;

int getDiff(vector<int> v){
    int sumA = 0;
    for(int i=0; i<v.size()-1; i++)
        for(int j=i+1; j<v.size(); j++)
            sumA += S[v.at(i)][v.at(j)];

    vector<int> rv;
    int cnt=0;
    bool flag=0;
    for(int i=0; i<N; i++){
        flag = 0;
        for(int j=cnt; j<v.size(); j++){
            if(i==v.at(j)) {
                flag=1;
                cnt++;
                break;
            }
        }
        if(!flag) rv.push_back(i);
    }

    int sumB = 0;
    for(int i=0; i<rv.size()-1; i++)
        for(int j=i+1; j<rv.size(); j++)
            sumB += S[rv.at(i)][rv.at(j)];

    return abs(sumA-sumB);
}

int facto(int s, int e){
    int sum = 1;

    for(int i=s; i<=e; i++) sum*=i;
    return sum;
}

int main(int argc, char const *argv[])
{
    cin>>N;

    S = new int*[N];
    for(int i=0; i<N; i++) S[i] = new int[N];
    for(int i=0; i<N*N; i++) cin>>S[i/N][i%N];

    for(int i=0; i<N; i++) for(int j=i; j<N; j++) S[i][j] += S[j][i];

    vector<int> v;
    for(int i=0; i<N/2; i++) v.push_back(i);
    int cnt=0;
    for(int i=0; i<facto(N/2+1, N)/(N/2); i++){
        int b = v.back();
        v.pop_back();
        if(b == N-1) v.pop_back();
        v.push_back(b+1);
    }
    cout<<getDiff(v);
    
    return 0;
}
