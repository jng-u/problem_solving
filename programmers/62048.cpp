#include <iostream>
#include <cmath>

int gcd(int m, int n) {
    int r = 0, a, b;
    a = (m > n) ? m : n;
    b = (m < n) ? m : n;
    r = b;
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

long long solution(int w, int h) {
    long long answer = 1;

    int N = gcd(w, h);
    int g = (w > h) ? w : h;
    int l = (w < h) ? w : h;
    g /= N;
    l /= N;
    float d = (float)g/l;
    int dnum = 0;
    for(int i=1; i<=l; i++) dnum += ceil(d*i) - floor(d*(i-1));
    // int dnum = l*ceil(d);
    answer = w*h-dnum*N;
    return answer;
}

int main(int argc, char const *argv[]) {
    int W=8;
    int H=12;
    std::cout<<solution(W, H)<<"\n";

    return 0;
}
