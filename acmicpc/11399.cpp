/**
 * 백준 11399번
 * ATM
 * 그리디 알고리즘
 */
#include <iostream>
using namespace std;

void bitonic(int *arr, int s, int e){
    int l = e-s;
    if(l<2) return ;
    int m = (s+e)/2;
    bitonic(arr, s, m);
    bitonic(arr, m, e);

    int f=s, b=m;
    int *tmp = new int[l];
    int idx=0;
    while(true){
        if(arr[f]<arr[b]){
            tmp[idx++] = arr[f++];
        } else {
            tmp[idx++] = arr[b++];
        }

        if(f>=m){
            while(b<e)
                tmp[idx++] = arr[b++];
            break;
        } else if(b>=e){
            while(f<m)
                tmp[idx++] = arr[f++];
            break;
        }
    }

    for(int i=0; i<l; i++) arr[s+i] = tmp[i];
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int *P = new int[N];
    for(int i=0; i<N; i++) cin>>P[i];

    bitonic(P, 0, N);

    int ans=0;
    for(int i=0; i<N; i++) ans += P[i]*(N-i);

    cout<<ans<<"\n";
    
    return 0;
}
