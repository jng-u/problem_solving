/**
 * 백준 2749번
 * 피보나치 수 3
 * divide & conquer
 */
#include <iostream>
using namespace std;
#define M 1000000

int **mul(int **A, int **B){
    int **C = new int*[2];
    for(int i=0; i<2; i++) C[i] = new int[2];
    
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            C[i][j] = 0;
            for(int k=0; k<2; k++){
                C[i][j] += ((long long)A[i][k]*B[k][j])%M;
            }
            C[i][j] %= M;
        }
    }
    return C;
}

int **power(int **A, long long n){
    if(n==1) return A;
    else {
        int **P = power(A, n/2);
        if(n%2==0) return mul(P, P);
        else return mul(A, mul(P, P));
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin>>n;

    // int a=0, b=1, c;
    // for(int i=1; i<n; i++){
    //     c = (a+b) % 1000000;
    //     a = b;
    //     b = c;
    // }
    // cout<<c<<"\n";

    int **A = new int*[2];
    for(int i=0; i<2; i++) A[i] = new int[2];
    A[0][0]=1; A[0][1]=1;
    A[1][0]=1; A[1][1]=0;

    if(n==0) cout<<"0\n";
    else if(n==1) cout<<"1\n";
    else {
        int **P = power(A, n-1);
        cout<<P[0][0]<<"\n";
    }

    return 0;
}
