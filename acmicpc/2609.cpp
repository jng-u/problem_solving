/**
 * 백준 2609번
 * 최대공약수와 최소공배수
 * 정수론과 조합론
 */
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int gcd(int a, int b){
    if(b>a) swap(a, b);
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    int g = gcd(a, b);
    return a*b/g;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B;
    cin>>A>>B;

    cout<<gcd(A, B)<<"\n"<<lcm(A, B)<<"\n";
    
    return 0;
}
