#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = INT64_MAX;

    int N = land.size();
    N *= N;

    std::vector<int> flat;
    for (auto row : land) 
        flat.insert(flat.end(), row.begin(), row.end()); 
    std::sort(flat.begin(), flat.end());

    uint64_t sum = 0;
    for(auto val : flat) sum += val;
    uint64_t area_fill = 0;
    uint64_t to_fill = 0;
    uint64_t area_remove = N;
    uint64_t to_remove = sum;

    int flat_idx=0;
    for (int i=0; i<=1000000000; ++i) {
        int count = 0;
        while (i != flat[flat_idx]) {
            i++;
            to_fill += area_fill;
            to_remove -= area_remove;
        }
        while (flat_idx < N && i == flat[flat_idx]) {
            flat_idx++;
            count++;
        } 
        if (flat_idx >= N) break;
        
        uint64_t cost = to_fill*P + to_remove*Q;
        if(cost < answer) answer = cost;
        area_fill += count;
        to_fill += area_fill;
        area_remove -= count;
        to_remove -= area_remove;
    }
    uint64_t cost = to_fill*P + to_remove*Q;
    if(cost < answer) answer = cost;

    return answer;
}

int main(int argc, char const *argv[]) {
    // std::vector<std::vector<int>> land = {{1, 2}, {2, 3}};
    // int P = 3;
    // int Q = 2;

    std::vector<std::vector<int>> land = {{4, 4, 3}, {3, 2, 2}, { 2, 1, 0 }};
    // std::vector<std::vector<int>> land = {{4, 5, 3}, {3, 1, 2}, { 2, 1, 0 }};
    int P = 5;
    int Q = 3;

    long long answer = solution(land, P, Q);
    std::cout<<answer<<"\n";
    return 0;
}
