/**
 * 백준 19946번
 * 2의 제곱수 계산하기
 * 2020 IGRUS Newbie Programming Contest C번
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    unsigned long long n;
    cin>>n;

    if(n==18446744073709551615) {
        cout<<"64\n";
        return 0;
    }

    n>>=1;
    unsigned long long pivot = 9223372036854775808;
    int cnt=63;
    while(pivot-1 != n){
        n>>=1;
        pivot>>=1;
        cnt--;
    }

    cout<<cnt<<"\n";

    return 0;
}
