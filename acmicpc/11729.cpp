#include <iostream>
#include <cstdio>
using namespace std;

void hanoi(int n, int s, int e){
    if(n){
        hanoi(n-1, s, 6-s-e);
        printf("%d %d\n", s, e);
        hanoi(n-1, 6-s-e, e);
    }
}

int main(){
    int n;
    cin>>n;

    int a=1;
    for(int i=0; i<n; i++){
        a*=2;
    }
    printf("%d\n", a-1);
    hanoi(n, 1, 3);

    return 0;
}
