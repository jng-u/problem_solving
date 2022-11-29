/**
 * 백준 11650번
 * 좌표 정렬하기
 */

#include <iostream>
using namespace std;

struct position{
    int x;
    int y;
};

bool operator <(position &a, position &b){
    if(a.x < b.x) return true;
    else if(a.x == b.x && a.y < b.y) return true;
    else return false;
}

bool operator <=(position &a, position &b){
    if(a.x < b.x) return true;
    else if(a.x == b.x && a.y <= b.y) return true;
    else return false;
}

bool operator >(position &a, position &b){
    if(a.x > b.x) return true;
    else if(a.x == b.x && a.y > b.y) return true;
    else return false;
}

bool operator >=(position &a, position &b){
    if(a.x > b.x) return true;
    else if(a.x == b.x && a.y >= b.y) return true;
    else return false;
}

void swap(position &a, position &b){
    position tmp = a;
    a = b;
    b = tmp;
}

// void quick(position *arr, const int &s, const int &e){
//     int ps=s, pe=e;
//     int m = (s+e)/2;
//     if(arr[s]>arr[m]) swap(arr[s], arr[m]);
//     if(arr[m]>arr[e]) swap(arr[m], arr[e]);
//     if(arr[s]>arr[m]) swap(arr[s], arr[m]);
//     if(e-s<3) return ;
//
//     ps++; pe--;
//     int pivot=pe;
//     swap(arr[pivot], arr[m]);
//     while(true){
//         while(ps<=pe && arr[ps] < arr[pivot]) ps++;
//         if(ps>=pe) break;
//         while(ps<=pe && arr[pivot] < arr[pe]) {
//             pe--;
//         }
//         if(ps>=pe) break;
//         swap(arr[ps], arr[pe]);
//     }
//     swap(arr[pe], arr[pivot]);
//  
//     if(s<pe) quick(arr, s, pe-1);
//     if(pe<e) quick(arr, pe+1, e);
// }

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
    
    // quick(poss, 0, N-1);
    merge(poss, 0, N-1);
    
    // cout<<"======================\n";
    for(int i=0; i<N; i++){
        cout<<poss[i].x<<" "<<poss[i].y<<"\n";
    }
    
    return 0;
}
