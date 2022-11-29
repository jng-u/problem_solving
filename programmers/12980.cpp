#include <iostream>

int main(int argc, char const *argv[])
{
    int N = (int)(*argv[1])-'0';
    int cnt = 1;
    while(N != 1){
        if(N%2==1) {
            N-=1;
            cnt++;
        }
        N/=2;
    }
    std::cout<<cnt<<"\n";
    return 0;
}
