/**
 * 백준 19950번
 * 3차원 막대기 연결하기 
 * 2020 IGRUS Newbie Programming Contest G번
 */
#include <iostream>
using namespace std;

struct point{
    int x, y, z;
};

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    point start, end;
    cin>>start.x>>start.y>>start.z;
    cin>>end.x>>end.y>>end.z;

    int N;
    cin>>N;
    int *lens = new int[N];
    for(int i=0; i<N; i++) cin>>lens[i];

    return 0;
}
