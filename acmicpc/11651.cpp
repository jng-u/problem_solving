/**
 * 백준 11651번
 * 좌표 정렬하기2
 */

#include <iostream>
using namespace std;

struct position{
    int x;
    int y;
};

bool operator <(position &a, position &b){
    if(a.y < b.y) return true;
    else if(a.y == b.y && a.x < b.x) return true;
    else return false;
}

bool operator <=(position &a, position &b){
    if(a.y < b.y) return true;
    else if(a.y == b.y && a.x <= b.x) return true;
    else return false;
}

bool operator >(position &a, position &b){
    if(a.y > b.y) return true;
    else if(a.y == b.y && a.x > b.x) return true;
    else return false;
}

bool operator >=(position &a, position &b){
    if(a.y > b.y) return true;
    else if(a.y == b.y && a.x >= b.x) return true;
    else return false;
}

void swap(position &a, position &b){
    position tmp = a;
    a = b;
    b = tmp;
}

void merge(position *arr, const int &s, const int &e){
    int len = e-s+1;
    if(len==1) return ;
    int m = (s+e)/2;
    merge(arr, s, m);
    merge(arr, m+1, e);

    position *tmp = new position[len];
    int cnt=0;
    int l=s, r=m+1;
    while(true){
        if(arr[l]<=arr[r]) {
            tmp[cnt] = arr[l];
            cnt++; l++;
            if(l>m){
                while(r<=e){
                    tmp[cnt] = arr[r];
                    cnt++; r++;
                }
                break;
            }
        } else {
            tmp[cnt] = arr[r];
            cnt++; r++;
            if(r>e){
                while(l<=m){
                    tmp[cnt] = arr[l];
                    cnt++; l++;
                }
                break;
            }
        }
    }
    for(int i=0; i<len; i++){
        arr[s+i] = tmp[i];
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    position *poss = new position[N];
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        poss[i].x = x;
        poss[i].y = y;
    }
    
    merge(poss, 0, N-1);
    
    // cout<<"======================\n";
    for(int i=0; i<N; i++){
        cout<<poss[i].x<<" "<<poss[i].y<<"\n";
    }
    
    return 0;
}
