/**
 * 백준 1085번
 * 직사각형에서 탈출
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x, y, w, h;
    cin>>x>>y>>w>>h;
    int min = (x < y)? x : y;
    min = (min < w-x)? min : w-x;
    min = (min < h-y)? min : h-y;

    cout<<min<<"\n";
    
    return 0;
}
