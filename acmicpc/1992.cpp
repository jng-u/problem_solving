/**
 * 백준 1992번
 * 쿼드트리
 * divide & conquer
 */
#include <iostream>
#include <string>
using namespace std;

int check(int video[64][64], int x, int y, int size){
    int c = video[y][x];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(video[y+i][x+j] != c) return -1;
        }
    }
    return c;
}

void compress(int video[64][64], int x, int y, int size){
    int c = check(video, x, y, size);
    if(c<0){
        size>>=1;
        cout<<"(";
        compress(video, x, y, size);
        compress(video, x+size, y, size);
        compress(video, x, y+size, size);
        compress(video, x+size, y+size, size);
        cout<<")";
    }
    else cout<<c;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int video[64][64];
    for(int i=0; i<N; i++){
        string n;
        cin>>n;
        for(int j=0; j<N; j++){
            video[i][j] = n[j]-'0';
        }
    }

    compress(video, 0, 0, N);
    cout<<"\n";
    
    return 0;
}
