#include <iostream>
#include <vector>

int count(int n){
    if(n<=1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 3;
    else return count(n-1) + count(n-2);
}

int main(int argc, char const *argv[])
{
    int N, M;
    std::cin>>N>>M;
    std::vector<int> counts;
    int loc = 0;
    for(int i=0; i<M; i++) {
        int vip;
        std::cin>>vip;

        int len = vip-loc-1;
        counts.push_back(count(len));
        loc = vip;
    }
    counts.push_back(count(N-loc));

    int ans = 1;
    for(auto c : counts) ans *= c;
    std::cout<<ans<<"\n";


    return 0;
}
