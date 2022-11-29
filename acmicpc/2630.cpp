/**
 * 백준 2630번
 * 색종이 만들기
 * divide & conquer
 */
#include <iostream>
using namespace std;

int white = 0;
int blue = 0;

int check(int paper[128][128], int x, int y, int size){
    int c = paper[y][x];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(paper[y+i][x+j] != c) return -1;
        }
    }
    return c;
}

void cut(int paper[128][128], int x, int y, int size){
    int c = check(paper, x, y, size);
    if(c<0){
        size>>=1;
        cut(paper, x, y, size);
        cut(paper, x+size, y, size);
        cut(paper, x, y+size, size);
        cut(paper, x+size, y+size, size);
    }
    else if(c==0) white++;
    else if(c==1) blue++;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    int paper[128][128];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>paper[i][j];

    cut(paper, 0, 0, N);
    cout<<white<<"\n"<<blue<<"\n";
    
    return 0;
}
