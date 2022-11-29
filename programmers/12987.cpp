#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> A = {5, 1, 3, 7};
    std::vector<int> B = {2, 2, 6, 8};

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int cnt = 0;
    while(!A.empty()) {
        if(A.back() < B.back()) {
            A.pop_back();
            B.pop_back();
            cnt++;
        } else {
            A.pop_back();
        }
    }
    std::cout<<cnt<<"\n";
    
    return 0;
}
