/**
 * 백준 2108번
 * 통계학
 * 정렬을 활용해보자
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int avg=0;
    int mid;
    int min=4000, max=-4000;
    int count[8001] = {0, };
    int max_freq=0;
    int maxfre_value;
    for(int i=0; i<N; i++){
        int n;
        cin>>n;
        avg += n;
        if(n<min) min=n;
        if(n>max) max=n;
        count[n+4000]++;
        if(count[n+4000]>max_freq) max_freq=count[n+4000];
    }

    avg = round((float)avg/N);
    
    int accum=-1;
    int maxfre_count=0;
    for(int i=0; i<8001; i++){
        accum+=count[i];
        if(accum-count[i]<N/2 && accum>=N/2) mid=i-4000;

        if(maxfre_count<2 && count[i]==max_freq) {
            maxfre_value = i-4000;
            maxfre_count++;
        }
    }

    cout<<avg<<"\n";
    cout<<mid<<"\n";
    cout<<maxfre_value<<"\n";
    cout<<max-min<<"\n";

    // for(int i=1; i<=10000; i++){
    //     while(count[i]--){
    //         cout<<i<<"\n";
    //     }
    // }
    
    return 0;
}
