/**
 * 백준 1780번
 * 종이의 개수
 * divide & conquer
 */
#include <iostream>
#include <string>
using namespace std;

int paper[2187][2187];
int count[3] = {0, };

int check(int x, int y, int size){
    int c = paper[y][x];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(paper[y+i][x+j] != c) return -1;
        }
    }
    return c;
}

void divide(int x, int y, int size){
    int c = check(x, y, size);
    if(c<0){
        size/=3;
        divide(x, y, size);
        divide(x+size, y, size);
        divide(x+size*2, y, size);
        divide(x, y+size, size);
        divide(x+size, y+size, size);
        divide(x+size*2, y+size, size);
        divide(x, y+size*2, size);
        divide(x+size, y+size*2, size);
        divide(x+size*2, y+size*2, size);
    }
    else count[c]++;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int c;
            cin>>c;
            paper[i][j] = ++c;
        }
    }

    divide(0, 0, N);
    for(int i=0; i<3; i++) cout<<count[i]<<"\n";
    
    return 0;
}
