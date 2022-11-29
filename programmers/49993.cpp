#include <string>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string skill = "CBD";
    std::vector<std::string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    int answer = 0;
    for(auto skill_tree : skill_trees){
        bool flag = true;
        int idx = 0;
        for(auto s : skill){
            int nidx = skill_tree.find(s);
            if (nidx == -1) nidx = 30;
            if (nidx < idx) {
                flag = false;
                break;
            }
            idx = nidx;
        }
        if(flag) answer++;
    }
    std::cout<<answer<<"\n";

    return 0;
}
