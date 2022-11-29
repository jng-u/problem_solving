/**
 * 백준 19944번
 * 뉴비의 기준은 뭘까?
 * 2020 IGRUS Newbie Programming Contest A번
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;
    
    if(M==1 || M==2){
        cout<<"NEWBIE!\n";
    } else if(M<=N) {
        cout<<"OLDBIE!\n";
    } else {
        cout<<"TLE!\n";
    }

    return 0;
}
