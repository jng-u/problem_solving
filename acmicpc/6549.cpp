/**
 * 백준 6549번
 * 히스토그램에서 가장 큰 직사각형
 * divide & conquer
 */
#include <iostream>
using namespace std;

int *make_tree(int *arr, int size){
    int *ret = new int[2*size];
    for(int i=size; i<2*size; i++) ret[i] = arr[i-size];
    for(int i=size-1; i>0; i--) ret[i] = min(ret[i<<1], ret[i<<1|1]);
    return ret;
}

int min_seg(int *tree, int size, int l, int r){
    l += size;
    r += size;
    int ret = 1000000000;
    while(true){
        if(l%2==1) ret = min(ret, tree[l++]);
        if(r%2==0) ret = min(ret, tree[r--]);
        if(l>r) break;
        l>>=1;
        r>>=1;
    }
    return ret;
}

long long get_max(int *tree, int size, int s, int e){
    int m = (s+e)/2;
    long long max_val=0;
    for(int i=0; i<size; i++){
        int a = (i<m)? i : m;
        int b = (i>m)? i : m;
        max_val = max(max_val, (long long)((b+1-a)*min_seg(tree, size, a, b)));
    }
    if(s<=m-1) max_val = max(max_val, get_max(tree, size, s, m-1));
    if(m+1<=e) max_val = max(max_val, get_max(tree, size, m+1, e));
    return max_val;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int n=0;
        cin>>n;
        if(n==0) break;

        int *h = new int[n];
        for(int i=0; i<n; i++) cin>>h[i];
        int* tree = make_tree(h, n);

        // long long _max=0;
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         _max = max(_max, (long long)((j+1-i)*min_seg(h, n, i, j)));
        //     }
        // }

        cout<<get_max(tree, n, 0, n-1)<<"\n";

    }

    return 0;
}
