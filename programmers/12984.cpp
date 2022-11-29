#include <iostream>
#include <vector>
#include <map>

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> land = {{1, 2}, {2, 3}};
    int P=3, Q=2;
    // std::vector<std::vector<int> > land = {{4, 4, 3}, {3, 2, 2}, { 2, 1, 0 }};
    // int P=5, Q=3;

    long long answer=0;

    std::map<int, int> land_map;
    for (std::vector<int> row : land) {
        for (int value : row) {
            std::map<int, int>::iterator value_iter = land_map.find(value);
            if (value_iter == land_map.end()) land_map.insert({value, 1});
            else value_iter->second++;
        }
    }

    int m = 1;
    while (m < 1000000001) {
        
    }


    std::vector<int> base(1000000001);

    for (int i=0; i<1000000001; i++) {
        std::cout << iter.first << " " << iter.second << "\n";
    }

    // for ()
    
    return 0;
}
