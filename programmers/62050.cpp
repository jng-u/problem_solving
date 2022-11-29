#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> land = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
    int height = 3;
    int width = land.size();
    std::vector<std::vector<int>> edges(width, std::vector<int>(width));
    for(int i=0; i<width*width; i++) {
        land[i/width][i%width]
    }
    return 0;
}

