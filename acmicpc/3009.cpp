/**
 * 백준 3009번
 * 네 번째 점
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;

    int x4, y4;
    x4 = (x1 != x2)? ((x1 != x3)? x1 : x2) : x3;
    y4 = (y1 != y2)? ((y1 != y3)? y1 : y2) : y3;

    cout<<x4<<" "<<y4<<"\n";
    
    return 0;
}
