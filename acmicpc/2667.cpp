#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//dfs
void spread(int **arr, int x, int y, int num, int &count){
	arr[x][y] = num;
	count++;
	if(arr[x+1][y]==1) spread(arr, x+1, y, num, count);
	if(arr[x][y+1]==1) spread(arr, x, y+1, num, count);
	if(arr[x-1][y]==1) spread(arr, x-1, y, num, count);
	if(arr[x][y-1]==1) spread(arr, x, y-1, num, count);
}

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int **apt = new int*[N+2];
	for(int i=0; i<N+2; i++) apt[i]=new int[N+2]();

	for(int i=0; i<N+2; i++){
		apt[0][i]=0;
		apt[i][0]=0;
		apt[N+1][i]=0;
		apt[i][N+1]=0;
	}

	int cnt=1;
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			char c;
			cin>>c;
			apt[i][j] = c-'0';
		}
	}

	map<int, int> count;
	vector<int> ans;
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			if(apt[i][j]==1){
				cnt++;
				count.insert(pair<int, int>(cnt, 0));
				spread(apt, i, j, cnt, count.find(cnt)->second);
				ans.push_back(count.find(cnt)->second);
			}
		}
	}

	sort(ans.begin(), ans.end());
	// for(int i=1; i<N+1; i++){
	// 	for(int j=1; j<N+1; j++){
	// 		cout<<apt[i][j];
	// 	}
	// 	cout<<endl;
	// }

	cout<<cnt-1<<endl;
	for(int i=0; i<ans.size(); i++) cout<<ans.at(i)<<endl;

	return 0;
}
