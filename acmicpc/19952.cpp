/**
 * 백준 19952번
 * 인성 문제 있어?? 
 * 2020 IGRUS Newbie Programming Contest I번
 * 문제 개빡치게 가로W 세로H라고 해놓고
 * 좌표는 가로y 세로x 이게 뭔 말도 안되는 변수 이름이냐 빠꺼
 */
#include <iostream>
#include <queue>
using namespace std;

struct point{
    int x, y;
};

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int H, W, O, F;
        cin>>H>>W>>O>>F;
        int **map = new int*[H+1];
        for(int i=0; i<=H; i++) map[i] = new int[W+1];
        for(int i=0; i<=H; i++) for(int j=0; j<=W; j++) map[i][j] = 0;
        
        point start, end;
        cin>>start.y>>start.x>>end.y>>end.x;
        for(int i=0; i<O; i++){
            int x, y;
            cin>>y>>x;
            cin>>map[y][x];
        }

        // for(int i=1; i<=H; i++) {
        //     for(int j=1; j<=W; j++){
        //         cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

        int **dp = new int*[H+1];
        for(int i=0; i<=H; i++) dp[i] = new int[W+1];
        for(int i=0; i<=H; i++) for(int j=0; j<=W; j++) dp[i][j] = -1;
        queue<point> pts;
        pts.push(start);
        dp[start.y][start.x] = F;
        while(true){
            if(pts.empty()) break;
            point curr = pts.front();
            pts.pop();
            int x = curr.x;
            int y = curr.y;
            if(dp[y][x] == 0) continue;
            if(x<W && dp[y][x] >= map[y][x+1] - map[y][x]){
                if(dp[y][x+1]==-1) pts.push({x+1, y});
                dp[y][x+1] = max(dp[y][x+1], dp[y][x]-1);
            }
            if(y<H && dp[y][x] >= map[y+1][x] - map[y][x]){
                if(dp[y+1][x]==-1) pts.push({x, y+1});
                dp[y+1][x] = max(dp[y+1][x], dp[y][x]-1);
            }
            if(x>1 && dp[y][x] >= map[y][x-1] - map[y][x]){
                if(dp[y][x-1]==-1) pts.push({x-1, y});
                dp[y][x-1] = max(dp[y][x-1], dp[y][x]-1);
            }
            if(y>1 && dp[y][x] >= map[y-1][x] - map[y][x]){
                if(dp[y-1][x]==-1) pts.push({x, y-1});
                dp[y-1][x] = max(dp[y-1][x], dp[y][x]-1);
            }
            if(dp[end.y][end.x] != -1) break;
        }

        if(dp[end.y][end.x] != -1){
            cout<<"잘했어!!\n";
        } else {
            cout<<"인성 문제있어??\n";
        }

    }

    return 0;
}
