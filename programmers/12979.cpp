#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    // int n = 11;
    // std::vector<int> stations = {4, 11};
    // int w = 1;
    int n = 16;
    std::vector<int> stations = {8};
    int w = 2;

    std::sort(stations.begin(), stations.end());
    stations.push_back(n+w+1);

    int answer = 0;
    int w_size = w*2+1;
    int lower=1;
    for(auto station : stations){
        if(station-w > lower){
            answer += (station-w - lower - 1)/w_size + 1;
        }
        lower = station+w+1;
    }
    std::cout<<answer<<"\n";

    return 0;
}
