/**
 * 백준 19951번
 * 태상이의 훈련소 생활  
 * 2020 IGRUS Newbie Programming Contest H번
 */
#include <iostream>
using namespace std;

void bitonic(int *arr, int *arr2, int s, int e){
    int len = e-s;
    if(len < 2) return ;

    int m = (s+e)/2;
    bitonic(arr, arr2, s, m);
    bitonic(arr, arr2, m, e);

    int *tmp = new int[len];
    int *tmp2 = new int[len];
    int idx=0;
    int fi=s, bi=m;
    while(true){
        if(arr[fi]<arr[bi]){
            tmp[idx] = arr[fi];
            tmp2[idx] = arr2[fi];
            idx++; fi++;
        } else {
            tmp[idx] = arr[bi];
            tmp2[idx] = arr2[bi];
            idx++; bi++;
        }

        if(fi >= m){
            while(bi < e){
                tmp[idx] = arr[bi];
                tmp2[idx] = arr2[bi];
                idx++; bi++;
            }
            break;
        } else if(bi >= e){
            while(fi < m){
                tmp[idx] = arr[fi];
                tmp2[idx] = arr2[fi];
                idx++; fi++;
            }
            break;
        }
    }
    for(int i=0; i<len; i++){
        arr[s+i] = tmp[i];
        arr2[s+i] = tmp2[i];
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;
    int *H = new int[N];
    for(int i=0; i<N; i++) cin>>H[i];
    int *a = new int[M];
    int *b = new int[M];
    int *k_a = new int[M];
    int *k_b = new int[M];
    for(int i=0; i<M; i++){
        cin>>a[i]>>b[i]>>k_a[i];
        k_b[i] = k_a[i];
    }
    bitonic(a, k_a, 0, M);
    bitonic(b, k_b, 0, M);

    // for(int i=0; i<M; i++) cout<<a[i]<<" "<<k_a[i]<<"\n";
    // for(int i=0; i<M; i++) cout<<b[i]<<" "<<k_b[i]<<"\n";

    int k=0;
    int front_idx=0;
    int back_idx=0;
    for(int i=1; i<=N; i++) {
        if(a[front_idx] <= i){
            while(a[front_idx] == i && front_idx<M) {
                k+=k_a[front_idx];
                front_idx++;
            }
        }
        if(b[back_idx] <= i){
            while(b[back_idx] < i && back_idx<M) {
                k-=k_b[back_idx];
                back_idx++;
            }
        }
        cout<<H[i-1]+k<<" ";
    }
    cout<<"\n";

    return 0;
}
