/**
 * 백준 14888번
 * 연산자 끼워넣기 
 * Back Tracking
 */
#include <iostream>
#include <vector>
using namespace std;

int *A;
int N;

int _max=-1000000000, _min=1000000000;

void calc(int level, int n, int *op){
    if(level==N-1){
        _max = (_max<n)? n : _max;
        _min = (_min>n)? n : _min;
    }

    for(int i=0; i<4; i++){
        if(op[i]){
            op[i]--;
            int m=n;
            if(i==0){
                m+=A[level+1];
            } else if(i==1){
                m-=A[level+1];
            } else if(i==2){
                m*=A[level+1];
            } else if(i==3){
                m/=A[level+1];
            }

            int tmp[4];
            for(int j=0; j<4; j++) tmp[j]=op[j];
            calc(level+1, m, tmp);
            op[i]++;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    A = new int[N];
    for(int i=0; i<N; i++) cin>>A[i];
    int add, sub, mul, div;
    cin>>add>>sub>>mul>>div;
    int op[4] = {0, };
    while(add--) op[0]++;
    while(sub--) op[1]++;
    while(mul--) op[2]++;
    while(div--) op[3]++;

    calc(0, A[0], op);

    cout<<_max<<"\n"<<_min<<"\n";

    return 0;
}