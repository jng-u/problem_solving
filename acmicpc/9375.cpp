/**
 * 백준 9375번
 * 패션왕 신해빈
 * 정수론과 조합론
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        vector<pair<string, int>> cloth;

        for(int i=0; i<N; i++){
            string name, type;
            cin>>name>>type;
            bool flag = false;
            for(int j=0; j<cloth.size(); j++){
                if(cloth[j].first == type) {
                    cloth[j].second++;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cloth.push_back(make_pair(type, 1));
            }
        }

        int count[31][31] = {0, };
        for(int i=1; i<=cloth.size(); i++){
            count[i][1] = cloth[i-1].second + count[i-1][1];
        } 
        for(int i=2; i<=cloth.size(); i++){
            for(int j=2; j<=i; j++) {
                count[i][j] = cloth[i-1].second*count[i-1][j-1] + count[i-1][j];
            }
        }

        int ans = 0;
        for(int i=1; i<=cloth.size(); i++) ans+=count[cloth.size()][i];
        cout<<ans<<"\n";
    }

    return 0;
}
