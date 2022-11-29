/**
 * 백준 11054번
 * 가장 긴 바이토닉 부분 수열 (LIS 응용)
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

    int inc_lens[1000] = {0, };
    inc_lens[0] = 1;
    for(int i=1; i<N; i++){
        int len = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]) len = (len > inc_lens[j])? len : inc_lens[j];    
        }
        if(len==0) inc_lens[i] = 1;
        else inc_lens[i] = len+1;
        // max_len = (max_len > inc_lens[i])? max_len : inc_lens[i];
    }
    
    int dec_lens[1000] = {0, };
    dec_lens[N-1] = 1;
    for(int i=N-2; i>=0; i--){
        int len = 0;
        for(int j=N-1; j>i; j--){
            if(arr[j] < arr[i]) len = (len > dec_lens[j])? len : dec_lens[j];    
        }
        if(len==0) dec_lens[i] = 1;
        else dec_lens[i] = len+1;
        // max_len = (max_len > inc_lens[i])? max_len : inc_lens[i];
    }
    
    // for(int i=0; i<N; i++) cout<<inc_lens[i]<<" ";
    // cout<<"\n";
    // for(int i=0; i<N; i++) cout<<dec_lens[i]<<" ";
    // cout<<"\n";

    int max_len=1;
    for(int i=0; i<N; i++) 
        max_len = (max_len > inc_lens[i]+dec_lens[i])? max_len : inc_lens[i]+dec_lens[i];

    cout<<max_len-1<<"\n";

    return 0;
}
