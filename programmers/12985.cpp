#include <iostream>

int main(int argc, char const *argv[])
{
    int N, A, B;
    N = 8;
    A = 4;
    B = 7;

    int answer = 0;
    while(A != B){
        A = (A+1)/2;
        B = (B+1)/2;
        answer++;
    }
    std::cout<<answer<<"\n";

    return 0;
}
