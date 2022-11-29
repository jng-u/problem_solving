/**
 * 백준 2981번
 * 검문
 * 정수론과 조합론
 */
#include <iostream>
#include <queue>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

void bitonic(int *arr, int s, int e){
    int l = e-s;
    if(l<2) return ;
    int m = (s+e)/2;
    bitonic(arr, s, m);
    bitonic(arr, m, e);

    int f=s, b=m;
    int idx=0;
    int *tmp = new int[l];
    while(true){
        if(arr[f]<arr[b]) tmp[idx++] = arr[f++];
        else tmp[idx++] = arr[b++];

        if(f>=m){
            while(b<e) tmp[idx++] = arr[b++];
            break;
        } else if(b>=e) {
            while(f<m) tmp[idx++] = arr[f++];
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

    int *numbers = new int[N];
    for(int i=0; i<N; i++) cin>>numbers[i];

    bitonic(numbers, 0, N);

    int *arr = new int[N];
    for(int i=1; i<N; i++) arr[i] = numbers[i] - numbers[i-1];
    for(int i=2; i<N; i++) arr[i] = (arr[i]>arr[i-1])? arr[i]-arr[i-1] : arr[i]+arr[i-1];

    int a = arr[1];

    int b = arr[N-1];

    if(b>a) swap(a, b);
    int g = gcd(a, b);
    for(int i=2; i<=g/2; i++) if(g%i==0) cout<<i<<" ";
    cout<<g;
    cout<<"\n";
    
    return 0;
}
