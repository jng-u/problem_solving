#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int N;
    std::cin>>N;
    std::vector<std::vector<int>> heights(N, std::vector<int>(N));
    std::unordered_set<int> hset;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            std::cin>>heights[i][j];
            hset.insert(heights[i][j]);
        }
    }
    std::vector<int> hsort(hset.begin(), hset.end());
    sort(hsort.begin(), hsort.end());

    int ans = 1;
    for(auto w : hsort) {
        std::vector<std::vector<bool>> check(N, std::vector<bool>(N, false));
        int label=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                std::stack<std::pair<int, int>> loc;
                if(!check[i][j]) {
                    check[i][j] = true;
                    if(heights[i][j] <= w) continue;

                    loc.push({i, j});
                    while(!loc.empty()) {
                        int y = loc.top().first;
                        int x = loc.top().second;
                        loc.pop();
                        if(y>0 && !check[y-1][x]) {
                            check[y-1][x] = true;
                            if(heights[y-1][x] > w) loc.push({y-1, x});
                        }
                        if(x>0 && !check[y][x-1]) {
                            check[y][x-1] = true;
                            if(heights[y][x-1] > w) loc.push({y, x-1});
                        }
                        if(y<N-1 && !check[y+1][x]) {
                            check[y+1][x] = true;
                            if(heights[y+1][x] > w) loc.push({y+1, x});
                        }
                        if(x<N-1 && !check[y][x+1]) {
                            check[y][x+1] = true;
                            if(heights[y][x+1] > w) loc.push({y, x+1});
                        }
                    }
                    label++;
                }
            }
        }
        ans = (ans>label)? ans:label;
    }

    std::cout<<ans<<'\n';

    
    return 0;
}
