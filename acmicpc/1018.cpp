/**
 * 백준 1018번
 * 체스판 다시 칠하기
 * 브루트포스
 */

#include <iostream>
using namespace std;

bool **board;

int get_cost(int x, int y){
    bool w_map[8][8], b_map[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2==0) {
                w_map[i][j] = 1;
                b_map[i][j] = 0;
            } else {
                w_map[i][j] = 0;
                b_map[i][j] = 1;
            }
        }
    }

    int w_cnt=0, b_cnt=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(w_map[i][j] != board[i+y][j+x]) w_cnt += 1;
            if(b_map[i][j] != board[i+y][j+x]) b_cnt += 1;
        }
    }
    
    return (w_cnt < b_cnt)? w_cnt : b_cnt;
}


int main(int argc, char const *argv[])
{
    int N, M;
    cin>>N>>M;
    board = new bool*[N];
    for(int i=0; i<N; i++) board[i] = new bool[M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin>>c;
            if(c=='B')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }

    int min=64;
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int c = get_cost(j, i);
            if(c < min) min=c;
        }
    }

    cout<<min<<"\n";
    
    return 0;
}
