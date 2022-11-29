#include <iostream>
#include <map>
using namespace std;

//dfs
void spread(int **arr, int y, int x, int num){
	arr[y][x] = num;
	if(arr[y+1][x]==1) spread(arr, y+1, x, num);
	if(arr[y][x+1]==1) spread(arr, y, x+1, num);
	if(arr[y-1][x]==1) spread(arr, y-1, x, num);
	if(arr[y][x-1]==1) spread(arr, y, x-1, num);
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for(int t_case=0; t_case<T; t_case++){
		int M, N, K;
		cin>>M>>N>>K;
		int **apt = new int*[N+2];
		for(int i=0; i<N+2; i++) apt[i]=new int[M+2]();

		for(int i=0; i<K; i++){
			int x, y;
			cin>>x>>y;
			apt[y+1][x+1] = 1;
		}

		int cnt=1;
		for(int i=1; i<N+1; i++){
			for(int j=1; j<M+1; j++){
				if(apt[i][j]==1){
					cnt++;
					spread(apt, i, j, cnt);
				}
			}
		}

		// for(int i=1; i<N+1; i++){
		// 	for(int j=1; j<N+1; j++){
		// 		cout<<apt[i][j];
		// 	}
		// 	cout<<endl;
		// }

		cout<<cnt-1<<endl;
	}

	return 0;
}
