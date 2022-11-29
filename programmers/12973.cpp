#include <string>
#include <iostream>
#include <stack>

int main(int argc, char const *argv[])
{
    std::string s = "baabaa";
    
    std::stack<char> stck;
    for(auto c : s) {
        if (!stck.empty() && stck.top() == c) stck.pop();
        else stck.push(c);
    }
    if(stck.empty()) std::cout<<"1\n";
    else std::cout<<s<<"\n";
    return 0;
}
