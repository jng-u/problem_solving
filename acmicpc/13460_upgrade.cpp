#include <iostream>
using namespace std;

int moveAll(char**, int);

void swap(char &a, char &b){
 	char t = a;
 	a = b;
 	b = t;
}

int h, w;
char **arr;

int move(char** og, int count, char direction){
	char **tmp;
	tmp = new char*[h];
	for(int i=0; i<h; i++)
		tmp[i] = new char[w];

	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			tmp[i][j] = og[i][j];

	int ch=0;
	if(direction=='L'){
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(tmp[i][j]=='R' || tmp[i][j]=='B'){
					int t = j;
					while(tmp[i][t-1]=='.') t--;
					swap(tmp[i][t], tmp[i][j]);
					ch++;
					continue;
				}
				if(tmp[i][j]=='R' || tmp[i][j]=='B'){
					int t = j;
					while(tmp[i][t-1]=='.') t--;
					swap(tmp[i][t], tmp[i][j]);
					ch++;
				}
			}
		}
	} else if(direction=='U'){
		for(int i=0; i<w; i++){
			for(int j=0; j<h; j++){
				if(tmp[j][i]=='R' || tmp[j][i]=='B'){
					int t = j;
					while(tmp[t-1][i]=='.') t--;
					swap(tmp[t][i], tmp[j][i]);
					ch++;
					continue;
				}
				if(tmp[j][i]=='R' || tmp[j][i]=='B'){
					int t = j;
					while(tmp[t-1][i]=='.') t--;
					swap(tmp[t][i], tmp[j][i]);
					ch++;
				}
			}
		}
	} else if(direction=='R'){
		for(int i=0; i<h; i++){
			for(int j=w-1; j>=0; j--){
				if(tmp[i][j]=='R' || tmp[i][j]=='B'){
					int t = j;
					while(tmp[i][t+1]=='.') t++;
					swap(tmp[i][t], tmp[i][j]);
					ch++;
					continue;
				}
				if(tmp[i][j]=='R' || tmp[i][j]=='B'){
					int t = j;
					while(tmp[i][t+1]=='.') t++;
					swap(tmp[i][t], tmp[i][j]);
					ch++;
				}
			}
		}
	} else if(direction=='D'){
		for(int i=0; i<w; i++){
			for(int j=h-1; j>=0; j--){
				if(tmp[j][i]=='R' || tmp[j][i]=='B'){
					int t = j;
					while(tmp[t+1][i]=='.') t++;
					swap(tmp[t][i], tmp[j][i]);
					ch++;
					continue;
				}
				if(tmp[j][i]=='R' || tmp[j][i]=='B'){
					int t = j;
					while(tmp[t+1][i]=='.') t++;
					swap(tmp[t][i], tmp[j][i]);
					ch++;
				}
			}
		}
	}

	if(ch==0) return -1;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(tmp[i][j]=='R' || tmp[i][j]=='B'){
				if(direction=='L'){
					if(tmp[i][j-1]=='O') {
						if(tmp[i][j]=='R' && tmp[i][j+1]!='B') return count;
						else return -1;
					}
				} else if(direction=='U'){
					if(tmp[i-1][j]=='O') {
						if(tmp[i][j]=='R' && tmp[i+1][j]!='B') return count;
						else return -1;
					}
				} else if(direction=='R'){
					if(tmp[i][j+1]=='O') {
						if(tmp[i][j]=='R' && tmp[i][j-1]!='B') return count;
						else return -1;
					}
				} else if(direction=='D'){
					if(tmp[i+1][j]=='O') {
						if(tmp[i][j]=='R' && tmp[i-1][j]!='B') return count;
						else return -1;
					}
				}
			}
		}
	}
	if(count==10) return -1;
	return moveAll(tmp, count+1);
}

int moveAll(char** og, int count){
	int ans=move(og, count, 'L');
	int tmp=move(og, count, 'U');
	if(ans==-1) ans=tmp;
	else if(tmp!=-1) ans = (ans>tmp) ? tmp : ans;
	tmp=move(og, count, 'R');
	if(ans==-1) ans=tmp;
	else if(tmp!=-1) ans = (ans>tmp) ? tmp : ans;
	tmp=move(og, count, 'D');
	if(ans==-1) ans=tmp;
	else if(tmp!=-1) ans = (ans>tmp) ? tmp : ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	cin>>h>>w;

	arr = new char*[h];
	for(int i=0; i<h; i++)
		arr[i] = new char[w];

	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cin>>arr[i][j];

	cout<<moveAll(arr, 1);

	return 0;
}
