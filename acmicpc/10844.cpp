/**
 * 백준 10844번
 * 쉬운 계단 수
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
    
    int nums[101][10];
    nums[0][0] = 0;
    for(int i=1; i<10; i++) nums[0][i] = 1;

    for(int i=1; i<N; i++){
        nums[i][0] = nums[i-1][1] % 1000000000;
        nums[i][9] = nums[i-1][8] % 1000000000;
        for(int j=1; j<9; j++){
            nums[i][j] = (nums[i-1][j-1] + nums[i-1][j+1]) % 1000000000;
        }    
    }

    int ans=0;
    for(int j=0; j<10; j++){
        ans += nums[N-1][j];
        ans %= 1000000000;
    }
    cout<<ans<<"\n";

    return 0;
}
