#include <iostream>
#include <list>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::list<int> w;
    for (int i=0; i<n*2; i++) {
        int wi;
        std::cin>>wi;
        w.push_back(wi);
    }

    w.sort();

    int min = 1000000;
    while(true) {
        int tmp = w.front() + w.back();
        if (tmp < min) min = tmp;

        w.pop_back();
        w.pop_front();
        if(w.empty()) break;
    }
    std::cout<<min<<"\n";

    return 0;
}