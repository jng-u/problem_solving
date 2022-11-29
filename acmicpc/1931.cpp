/**
 * 백준 1931번
 * 회의실배정
 * 그리디 알고리즘
 */
#include <iostream>
using namespace std;

void bitonic(int *arr, int *arr2, int s, int e){
    int l = e-s;
    if(l<2) return ;
    int m = (s+e)/2;
    bitonic(arr, arr2, s, m);
    bitonic(arr, arr2, m, e);

    int f=s, b=m;
    int *tmp = new int[l];
    int *tmp2 = new int[l];
    int idx=0;
    while(true){
        if(arr[f]<arr[b]){
            tmp[idx] = arr[f];
            tmp2[idx] = arr2[f];
            idx++; f++;
        } else if(arr[f]>arr[b]){
            tmp[idx] = arr[b];
            tmp2[idx] = arr2[b];
            idx++; b++;
        } else {
            if(arr2[f]<arr2[b]){
                tmp[idx] = arr[f];
                tmp2[idx] = arr2[f];
                idx++; f++;
            } else {
                tmp[idx] = arr[b];
                tmp2[idx] = arr2[b];
                idx++; b++;
            }
        }

        if(f>=m){
            while(b<e){
                tmp[idx] = arr[b];
                tmp2[idx] = arr2[b];
                idx++; b++;
            }
            break;
        } else if(b>=e){
            while(f<m){
                tmp[idx] = arr[f];
                tmp2[idx] = arr2[f];
                idx++; f++;
            }
            break;
        }
    }

    for(int i=0; i<l; i++){
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

    int *S = new int[N];
    int *E = new int[N];
    // unsigned int *D = new unsigned int[N];
    for(int i=0; i<N; i++) {
        cin>>S[i]>>E[i];
        // D[i] = e-S[i];
    }

    bitonic(E, S, 0, N);

    // for(int i=0; i<N; i++) 
    //     cout<<S[i]<<" "<<E[i]<<"\n";

    int *confirm_S = new int[N];
    int *confirm_E = new int[N];
    confirm_S[0] = S[0];
    confirm_E[0] = E[0];
    int idx=1;
    for(int i=1; i<N; i++){
        if(confirm_E[idx-1]<=S[i]){
            confirm_S[idx] = S[i];
            confirm_E[idx] = E[i];
            idx++;
        }
    }

    cout<<idx<<"\n";
    
    return 0;
}
