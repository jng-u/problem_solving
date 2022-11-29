/**
 * 백준 19947번
 * 투자의 귀재 배주형 
 * 2020 IGRUS Newbie Programming Contest D번
 */
#include <iostream>
using namespace std;

int max(int a, int b, int c){
    return max(max(a, b), c);
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int H, Y;
    cin>>H>>Y;

    int *dp = new int[11];
    dp[0] = H;
    for(int i=1; i<=Y; i++){
        if(i<3){
            dp[i] = dp[i-1]*105/100;
        } else if(i<5){
            dp[i] = max(dp[i-1]*105/100, dp[i-3]*120/100);
        } else {
            dp[i] = max(dp[i-1]*105/100, dp[i-3]*120/100, dp[i-5]*135/100);
        }
    }

    cout<<dp[Y]<<"\n";

    return 0;
}
