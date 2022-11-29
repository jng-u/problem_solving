/**
 * 백준 2565번
 * 전깃줄 (LIS 응용)
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

void bitonic_sort(int *arr, int *arr2, int s, int e){
    int len = e-s;
    if(len<2) return ;
    int m = (s+e)/2;
    bitonic_sort(arr, arr2, s, m);
    bitonic_sort(arr, arr2, m, e);
    int *tmp = new int[len];
    int *tmp2 = new int[len];
    int idx=0;
    int f=s, b=m;
    while(true){
        if(arr[f]<arr[b]) {
            tmp2[idx] = arr2[f];
            tmp[idx++] = arr[f++];
        }
        else {
            tmp2[idx] = arr2[b];
            tmp[idx++] = arr[b++];
        }

        if(f>=m){
            while(b<e) {
                tmp2[idx] = arr2[b];
                tmp[idx++] = arr[b++];
            }
            break;
        } else if(b>=e){
            while(f<m) {
                tmp2[idx] = arr2[f];
                tmp[idx++] = arr[f++];
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
    
	int N;
	cin>>N;

    int A[100], B[100];
    for(int i=0; i<N; i++) cin>>A[i]>>B[i];
    
    bitonic_sort(A, B, 0, N);

    int lens[100] = {0, };
    lens[0]=1;
    int max_len = 1;
    for(int i=1; i<N; i++){
        int len=0;
        for(int j=0; j<i; j++){
            if(B[j]<B[i]) len = (len > lens[j])? len : lens[j];
        }
        if(len==0) lens[i] = 1;
        else lens[i] = len+1;
        max_len = (max_len > lens[i])? max_len : lens[i];
    }
    cout<<N-max_len<<"\n";

    // for(int i=0; i<N; i++) cout<<A[i]<<" ";
    // cout<<"\n";
    // for(int i=0; i<N; i++) cout<<B[i]<<" ";
    // cout<<"\n";

    return 0;
}
