/**
 * 백준 19953번
 * 영재의 산책
 * 2020 IGRUS Newbie Programming Contest J번
 */
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int v0, m, t;
    cin>>v0>>m>>t;

    int n=v0;
    int e = (v0*m)%10;
    int s = (e*m)%10;
    int w = (s*m)%10;
    int step = t/4-1;
    int x=0, y=0;
    if(step>0){
        y += n;
        x += e;
        y -= s;
        x -= w;
        n = (w*m)%10;

        y += step*n;
        x += step*e;
        y -= step*s;
        x -= step*w;
    }

    int cnt=0;
    step = t - (step+1)*4;
    if(step == cnt){
        cout<<x<<" "<<y<<"\n";
        return 0;
    }
    y += n;
    cnt++;
    if(step == cnt){
        cout<<x<<" "<<y<<"\n";
        return 0;
    }
    x += e;
    cnt++;
    if(step == cnt){
        cout<<x<<" "<<y<<"\n";
        return 0;
    }
    y -= s;
    cnt++;
    if(step == cnt){
        cout<<x<<" "<<y<<"\n";
        return 0;
    }
    x -= w;
    cnt++;
    cout<<x<<" "<<y<<"\n";
        
    return 0;
}
