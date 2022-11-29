/**
 * 백준 2156번
 * 포도주 시식
 * Dynamic Programming
 */
#include <iostream>
using namespace std;

int max(int a, int b, int c){
    int max = (a>b)? a : b;
    max = (max>c)? max : c;
    return max;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	int N;
	cin>>N;

    int wines[10000] = {0, };
    for(int i=0; i<N; i++) cin>>wines[i];

    int drink[10000][3] = {0, };                //drink[i][0]: 1칸 건너뜀 //drink[i][1]: 2칸 건너뜀 //drink[i][2]: 3칸 건너뜀
    
    int max_val=wines[0];
    drink[0][0] = wines[0];
    drink[0][1] = wines[0];
    drink[0][2] = wines[0];
    if(N>1){
        drink[1][1] = wines[1];
        drink[2][2] = wines[1];
    }
    for(int i=1; i<N; i++){
        drink[i][0] = wines[i] + ((drink[i-1][1] > drink[i-1][2])? drink[i-1][1] : drink[i-1][2]);
        if(i>1) drink[i][1] = wines[i] + max(drink[i-2][0], drink[i-2][1], drink[i-2][2]);
        if(i>2) drink[i][2] = wines[i] + max(drink[i-3][0], drink[i-3][1], drink[i-3][2]);
        
        int max_i = max(drink[i][0], drink[i][1], drink[i][2]);
        max_val = (max_val > max_i)? max_val : max_i;
    }

    cout<<max_val<<"\n";


    return 0;
}
