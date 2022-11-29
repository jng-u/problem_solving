#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin>>N>>M;
	vector<int> *lines = new vector<int>[N+1];
	for(int i=0; i<M; i++){
		int a, b;
		cin>>a>>b;
		lines[a].push_back(b);
		lines[b].push_back(a);
	}

	int count=-1;
	int *visit = new int[N+1]();
	queue<int> queue;
	queue.push(1);
	while(1){
		if(queue.empty()) break;
		int node = queue.front();
		queue.pop();
		if(visit[node]==1) continue;
		visit[node]=1;
		count++;
		if(lines[node].empty()) continue;
		for(int i=0; i<lines[node].size(); i++){
			int e = lines[node].at(i);
			queue.push(e);
			for(int j=0; j<lines[e].size(); j++){
				if(lines[e].at(j)==node) lines[e].erase(lines[e].begin()+j);
			}
		}
		lines[node].clear();

	}

	cout<<count;

	return 0;
}
