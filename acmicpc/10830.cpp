/**
 * 백준 10830번
 * 행렬 제곱
 * divide & conquer
 */
#include <iostream>
using namespace std;

int **mul(int **A, int **B, int N){
    int **C = new int*[N];
    for(int i=0; i<N; i++) C[i] = new int[N];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = 0;
            for(int k=0; k<N; k++){
                C[i][j] += A[i][k]*B[k][j];
                C[i][j] %= 1000;
            }
        }
    }
    return C;
}


int **power(int **A, int N, long long B){
    if(B==1) return A;
    else {
        int **P = power(A, N, B/2);
        if(B%2==0) return mul(P, P, N);
        else return mul(A, mul(P, P, N), N);
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    long long B;
    cin>>N>>B;

    int **A = new int*[N];
    for(int i=0; i<N; i++) A[i] = new int[N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>A[i][j];
            A[i][j] %= 1000;
        }
    }

    int **P = power(A, N, B);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
