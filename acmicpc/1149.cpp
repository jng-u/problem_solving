/**
 * 백준 1149번
 * RGB거리
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
    
	int colors[1000][3] = {0, };
	for(int i=0; i<N; i++){
		cin>>colors[i][0]>>colors[i][1]>>colors[i][2];
	}

	int cost[3] = {colors[0][0], colors[0][1], colors[0][2]};
	int tmp[3] = {0, };
	for(int i=1; i<N; i++){
		tmp[0] = (cost[1] < cost[2])? cost[1] : cost[2];
		tmp[1] = (cost[0] < cost[2])? cost[0] : cost[2];
		tmp[2] = (cost[0] < cost[1])? cost[0] : cost[1];
		for(int j=0; j<3; j++){
			cost[j] = colors[i][j] + tmp[j];
		}
	}

	int min = (cost[0] < cost[1])? (cost[0] < cost[2])? cost[0] : cost[2] : (cost[1] < cost[2])? cost[1] : cost[2]; 
	// for(int i=0; i<3; i++)
	// 	cout<<cost[i]<<" ";
	cout<<min<<"\n";

    return 0;
}
