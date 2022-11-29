/**
 * 백준 2751번
 * 수 정렬하기 2
 * 정렬 (nlogn)
 */

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// void quick(int *arr, const int &s, const int &e){
//     int m = (s+e)/2;
//     int pivot = (arr[s]<arr[m] && arr[m]<arr[e])? m :
//                 (arr[m]<arr[s] && arr[s]<arr[e])? s :
//                 e;
//     // cout<<arr[s]<<" "<<arr[m]<<" "<<arr[e]<<"\n";
//     // cout<<pivot<<" : "<<arr[pivot]<<"\n";
//     swap(arr[pivot], arr[e]);
//     pivot = e;
//     int ps = s, pe = e;
//     while(true){
//         while(ps<=pe && arr[ps]<arr[pivot]) ps++;
//         if(ps >= pe) break;
//         while(ps<=pe && arr[pe]>arr[pivot]) pe--;
//         if(ps >= pe) break;
//         swap(arr[ps], arr[pe]);
//     }
//     swap(arr[ps], arr[pivot]);
//     if(s<ps-1) quick(arr, s, ps-1);
//     if(ps+1<e) quick(arr, ps+1, e);
// }

void merge(int *arr, const int &s, const int &e){
    if(s==e) return ;
    if(e-s==1){
        if(arr[s]>arr[e]) swap(arr[s], arr[e]);
        return ;
    }
    int m = (s+e)/2;
    merge(arr, s, m);
    merge(arr, m+1, e);
    
    int p=s, q=m+1;
    int *temp = new int[e-s+1];
    int temp_index=0;
    while(true){
        while(arr[p]<=arr[q] && p<m+1) temp[temp_index++] = arr[p++];
        if(p==m+1){
            while(q<e+1) temp[temp_index++] = arr[q++];
            break;
        }
        while(arr[q]<=arr[p] && q<e+1) temp[temp_index++] = arr[q++];
        if(q==e+1){
            while(p<m+1) temp[temp_index++] = arr[p++];
            break;
        }
    }
    for(int i=s; i<=e; i++){
        arr[i] = temp[i-s];
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    int *arr = new int[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    // quick(arr, 0, N-1);
    merge(arr, 0, N-1);

    for(int i=0; i<N; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    
    return 0;
}
