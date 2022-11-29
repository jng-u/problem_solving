/**
 * 백준 1932번
 * 정수 삼각형
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	int N;
	cin>>N;
    
    int tri[501][501] = {0, };
    for(int i=0; i<N; i++)
        for(int j=0; j<i+1; j++)
            cin>>tri[i][j];

    int max[501][501] = {0, };
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<i+1; j++){
            max[i][j] = tri[i][j] + ((max[i+1][j] > max[i+1][j+1])? max[i+1][j] : max[i+1][j+1]);
        }
    }

    cout<<max[0][0]<<"\n";

    return 0;
}
