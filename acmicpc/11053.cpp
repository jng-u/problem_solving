/**
 * 백준 11053번
 * 가장 긴 증가하는 부분 수열 (LIS)
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

    int arr[1000];
    for(int i=0; i<N; i++) cin>>arr[i];

    int max_len=1;
    int lens[1000] = {0, };
    lens[0] = 1;
    for(int i=1; i<N; i++){
        int len = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]) len = (len > lens[j])? len : lens[j];    
        }
        if(len==0) lens[i] = 1;
        else lens[i] = len+1;
        max_len = (max_len > lens[i])? max_len : lens[i];
    }

    cout<<max_len<<"\n";

    return 0;
}
