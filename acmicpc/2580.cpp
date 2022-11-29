/**
 * 백준 2580번
 * 스도쿠
 * Back Tracking
 */
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct point
{
    int x;
    int y;
};

bool ex_row[9][10]={{false, }}, ex_col[9][10]={{false, }}, ex_square[9][10]={{false, }};
int sdoku[9][9];

void visit(queue<point> order){
    point curr = order.front();
    order.pop();
    int si = curr.y/3*3 + curr.x/3;

    bool flag=false;
    for(int i=1; i<=9; i++){
        if(!ex_row[curr.y][i] && !ex_col[curr.x][i] && !ex_square[si][i]){
            sdoku[curr.y][curr.x] = i;
            ex_row[curr.y][i]=true;
            ex_col[curr.x][i]=true;
            ex_square[si][i]=true;

            if(order.empty()) {            
                for(int k=0; k<9; k++){
                    for(int j=0; j<9; j++){
                        cout<<sdoku[k][j]<<" ";
                    }
                    cout<<"\n";
                }
                exit(0);
            }

            visit(order);

            sdoku[curr.y][curr.x] = 0;
            ex_row[curr.y][i]=false;
            ex_col[curr.x][i]=false;
            ex_square[si][i]=false;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<point> order;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sdoku[i][j];
            if(sdoku[i][j]==0) order.push({j, i});
            ex_row[i][sdoku[i][j]]=true;
            ex_col[j][sdoku[i][j]]=true;
            int si = i/3*3 + j/3;
            ex_square[si][sdoku[i][j]]=true;
        }
    }
    
    visit(order);

    // cout<<"\n";
    // for(int i=0; i<9; i++){
    //     for(int j=0; j<9; j++){
    //         cout<<sdoku[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    return 0;
}