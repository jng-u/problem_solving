/**
 * 백준 19954번
 * 침략전쟁 
 * 2020 IGRUS Newbie Programming Contest L번
 */
#include <iostream>
#include <vector>
using namespace std;

struct kingdom{
    int capital;
    int territory;
    int power;
    // Border
    vector<int> borders;
};

int N, M, Q;
int **map;
vector<kingdom> kingdoms;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void progress_battle(int x1, int y1, int x2, int y2){
    int k1 = map[y1][x1]-1;
    int k2 = map[y2][x2]-1;
    if(k1==k2) return ;
    if(kingdoms[k1].power == kingdoms[k2].power) return ;

    if(kingdoms[k1].power < kingdoms[k2].power) swap(k1, k2);
    
    kingdoms[k1].territory += kingdoms[k2].territory-1;
    kingdoms[k2].territory = 1;

    kingdoms[k1].power -= kingdoms[k2].power;
    kingdoms[k2].power = 0;

    for(int i=0; i<kingdoms[k2].borders.size(); i++){
        int b = kingdoms[k2].borders[i];
        if(b==kingdoms[k2].capital) continue;
        kingdoms[k1].borders.push_back(b);
    }
    kingdoms[k2].borders.clear();
    kingdoms[k2].borders.push_back(kingdoms[k2].capital);


    for(int i=0; i<kingdoms[k1].borders.size(); i++){
        int b = kingdoms[k1].borders[i];
        int x = b%N;
        int y = b/N;
        if(x==0) {
            x = N;
            y--;
        }
        
        bool flag = false;
        for(int k=0; k<4; k++){
            int kx=x+dx[k], ky=y+dy[k];
            if(kx<=0 || kx>N) continue;
            if(ky<=0 || ky>N) continue;
            
            if(map[ky][kx] != k1+1) {
                flag = true;
                break;
            }
        }
        if(!flag) kingdoms[k1].borders.erase(kingdoms[k1].borders.begin()+i);
    }
}

void progress_draft(){
    for(int i=0; i<kingdoms.size(); i++){
        kingdoms[i].power += kingdoms[i].territory;
    }
}

void progress_expand(){
    vector<int> occupied;
    for(int i=0; i<kingdoms.size(); i++){
        for(int j=0; j<kingdoms[i].borders.size(); j++){
            int b = kingdoms[i].borders[j];
            int x = b%N;
            int y = b/N;
            if(x==0) { 
                x = N;
                y--;
            }
            // cout<<x<<" "<<y<<"\n";
            for(int k=0; k<4; k++){
                int kx=x+dx[k], ky=y+dy[k];
                if(kx<=0 || kx>N) continue;
                if(ky<=0 || ky>N) continue;
                
                if(map[ky][kx] == 0){
                    map[ky][kx] = -(i+1);
                    occupied.push_back(ky*N+kx);
                } else if(map[ky][kx] < 0){
                    // cout<<kx<<" "<<ky<<" "<<map[ky][kx]<<"\n";
                    if(kingdoms[i].power > kingdoms[-1*(map[ky][kx]-1)].power) map[ky][kx] = -(i+1);
                    else if(kingdoms[i].power == kingdoms[-1*(map[ky][kx]-1)].power){
                        cout<<kingdoms[i].power<<" "<<kingdoms[-1*(map[ky][kx]-1)].power<<"\n";
                        if(kingdoms[i].capital < kingdoms[-1*(map[ky][kx]-1)].capital) map[ky][kx] = -(i+1);
                        cout<<kx<<" "<<ky<<" "<<map[ky][kx]<<"\n";
                    
                    }
                }
            }
        }
    }
    for(int i=0; i<occupied.size(); i++){            
        int x = occupied[i]%N;
        int y = occupied[i]/N;
        if(x==0) {
            x = N;
            y--;
        }
        map[y][x]*=-1;
        int idx = map[y][x];
        kingdoms[idx-1].territory++;
        kingdoms[idx-1].borders.push_back(occupied[i]);
    }

    for(int i=0; i<kingdoms.size(); i++){
        for(int j=0; j<kingdoms[i].borders.size(); j++){
            int b = kingdoms[i].borders[j];
            int x = b%N;
            int y = b/N;
            if(x==0) {
                x = N;
                y--;
            }
            
            bool flag = false;
            for(int k=0; k<4; k++){
                int kx=x+dx[k], ky=y+dy[k];
                if(kx<=0 || kx>N) continue;
                if(ky<=0 || ky>N) continue;
                
                if(map[ky][kx] != i+1) {
                    flag = true;
                    break;
                }
            }
            if(!flag) kingdoms[i].borders.erase(kingdoms[i].borders.begin()+j);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M>>Q;
    map = new int*[N+1];
    for(int i=0; i<=N; i++) map[i] = new int[N+1];
    for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) map[i][j] = 0;

    for(int i=0; i<M; i++){
        int x, y, k;
        cin>>x>>y>>k;
        kingdoms.push_back({y*N+x, 1, k});
        kingdoms[i].borders.push_back(y*N+x);
        map[y][x] = i+1;
    }
    cout<<"\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    progress_draft();
    progress_expand();

    cout<<"\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    int d=1;
    while(Q--){
        int q, t;
        cin>>q>>t;
        while(d<t){   
            progress_draft();
            progress_expand();
            cout<<"\n";
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    cout<<map[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
            d++;
        }
        if(q==1){
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            progress_battle(x1, y1, x2, y2);
        } else if(q==2){
            int x, y;
            cin>>x>>y;
            cout<<kingdoms[map[y][x]-1].power<<"\n";
        }
    }

    // progress_draft();
    // progress_expand();
    // for(int n=0; n<5; n++){
    //     progress_draft();
    //     progress_expand();
    //     for(int i=1; i<=N; i++){
    //         for(int j=1; j<=N; j++){
    //             cout<<map[i][j]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }
        
    return 0;
}
