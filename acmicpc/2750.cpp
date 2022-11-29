/**
 * 백준 2750번
 * 수 정렬하기
 * 정렬 (n^2)
 */

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    int *arr = new int[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    for(int i=1; i<N; i++){
        int p = i;
        int min = arr[p];
        while(p>0 && arr[p-1]>arr[p]) {
            swap(arr[p-1], arr[p]);
            p--;
        }
    }

    for(int i=0; i<N; i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}
