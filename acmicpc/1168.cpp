/**
 * 백준 1168번
 * 요세푸스 문제 2
 * segment tree
 */
#include <iostream>
using namespace std;

int sum(int *tree, int size, int l, int r){
    l += size;
    r += size;
    int ans = 0;
    while(true){
        if(l&1) ans += tree[l++];
        if((r+1)&1) ans += tree[r--];
        if(l>r) break;
        l>>=1;
        r>>=1;
    }
    return ans;
}

void update(int *tree, int size, int i, int val){
    int n = size+i;
    tree[n] = val;
    while(n!=1){
        n>>=1;
        tree[n] = tree[n<<1] + tree[n<<1|1];
    } 
}

int next(int *tree, int size, int s, int K){
    K = K%tree[1];
    if(K==0) K = tree[1];
    int a = (s==0)? 0 : sum(tree, size, 0, s);
    int e = size-1;

    if(tree[1] - a < K) {
        K -= (tree[1] - a);
        a = 0;
    } else if(tree[1] - a == K) {
        while(tree[e+size]==0) e--;
        return e;
    }

    s = 0;
    int m = (s+e)/2;
    while(true){
        int b = sum(tree, size, 0, m);
        if(b-a == K){
            while(tree[m+size]==0) m--;
            return m;
        }
        else if(b-a < K){
            s = m;
            m = (s+e)/2;
        } else if(b-a > K){
            e = m;
            m = (s+e)/2;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    int *tree = new int[N*2];
    for(int i=N; i<2*N; i++) tree[i] = 1;
    for(int i=N-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];

    cout<<"<";
    int p = 0;
    while(tree[1]!=0){
        p = next(tree, N, p, K);
        update(tree, N, p, 0);
        cout<<p+1;
        if(tree[1]>0) cout<<", ";
    }
    cout<<">\n";

    return 0;
}
