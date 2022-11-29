#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define P int[2]

int N, M;

//dfs
/*
int spread(int **arr, int y, int x, int num){
	arr[y][x] = 0;
	num++;
	if(y==N && x==M) return num;
	int **cpy = new int*[N+2];
	for(int i=0; i<N+2; i++) cpy[i]=new int[M+2]();
	for(int i=0; i<N*M; i++) cpy[1+i/M][1+i%M] = arr[1+i/M][1+i%M];

	int ret, tmp;
	if(arr[y+1][x]==1) ret = spread(cpy, y+1, x, num);
	else ret = 200;
	if(arr[y][x+1]==1) tmp = spread(cpy, y, x+1, num);
	else tmp = 200;
	ret = (ret < tmp) ? ret : tmp;
	if(arr[y-1][x]==1) tmp = spread(cpy, y-1, x, num);
	else tmp = 200;
	ret = (ret < tmp) ? ret : tmp;
	if(arr[y][x-1]==1) tmp = spread(cpy, y, x-1, num);
	else tmp = 200;

	for(int i=0; i<N+2; i++) delete cpy[i];
	delete cpy;
	return (ret < tmp) ? ret : tmp;
}
*/

//bfs
int spread(int **arr, queue<int*> &points, int depth, vector<int> &cnt){
	int x = points.front()[0];
	int y = points.front()[1];
	points.pop();

	if(cnt.at(depth) == 0) {
		depth++;
		cnt.push_back(0);
	}
	if(y==N && x==M) return depth;

	if(arr[y][x+1]==1) {
		arr[y][x+1]=0;
		points.push(new P{x+1, y});
		cnt.at(depth+1)++;
	}
	if(arr[y-1][x]==1) {
		arr[y-1][x]=0;
		points.push(new P{x, y-1});
		cnt.at(depth+1)++;
	}
	if(arr[y][x-1]==1) {
		arr[y][x-1]=0;
		points.push(new P{x-1, y});
		cnt.at(depth+1)++;
	}
	if(arr[y+1][x]==1) {
		arr[y+1][x]=0;
		points.push(new P{x, y+1});
		cnt.at(depth+1)++;
	}
	cnt.at(depth)--;
	spread(arr, points, depth, cnt);
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	int **road = new int*[N+2];
	for(int i=0; i<N+2; i++) road[i]=new int[M+2]();

	for(int i=0; i<N*M; i++){
		if(i%M==0) getchar();
		road[1+i/M][1+i%M] = getchar()-'0';
	}

	// for(int i=1; i<N+1; i++){
	// 	for(int j=1; j<M+1; j++){
	// 		cout<<road[i][j];
	// 	}
	// 	cout<<endl;
	// }

	queue<int*> points;
	vector<int> *cnt = new vector<int>;
	points.push(new P{1, 1});
	cnt->push_back(1);
	cnt->push_back(0);
	road[1][1]=0;
	cout<<spread(road, points, 0, *cnt)+1;

	return 0;
}
