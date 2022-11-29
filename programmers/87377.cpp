#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

bool pred(std::vector<long long> a, std::vector<long long> b) {
    if(a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}
bool find_node(int a, int b, int e, int c, int d, int f, long long &x, long long &y) {
    long long xt, xb, yt, yb;
    xt = (long long)b*f - (long long)e*d;
    xb = (long long)a*d - (long long)b*c;
    yt = (long long)e*c - (long long)a*f;
    yb = (long long)a*d - (long long)b*c;
    if(xb == 0 || yb == 0) return false;
    if(yt%yb != 0 || xt%xb != 0) return false;
    x = xt/xb;
    y = yt/yb;
    return true;
}

int main(int argc, char const *argv[])
{
    // int line[5][3] = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    // size_t line_rows = 5, line_cols = 3;
    std::vector<std::vector<int>> line = {{0, 1, -1}, {1, 0, -1}, {1, 0, 1}};

    std::vector<std::vector<long long>> points;
    long long min_x=0, max_x=0, min_y=0, max_y=0;
    for(int i=0; i<line.size(); i++) {
        for(int j=i+1; j<line.size(); j++) {
            long long x=-1, y=-1;
            if(find_node(line[i][0], line[i][1], line[i][2], line[j][0], line[j][1], line[j][2], x, y)) {
                y = -y;
                if(points.empty()) {
                    min_x = x;
                    max_x = x;
                    min_y = y;
                    max_y = y;
                } else {
                    min_x = (min_x < x)? min_x : x;
                    min_y = (min_y < y)? min_y : y;
                    max_x = (max_x > x)? max_x : x;
                    max_y = (max_y > y)? max_y : y;
                }
                points.push_back({x, y});
            }
        }
    }
    std::sort(points.begin(), points.end(), pred);
    
    std::vector<std::string> answer;
    int idx=0;
    for(long long i=min_y; i<=max_y; i++) {
        std::string stars = "";
        for(long long j=min_x; j<=max_x; j++) {
            if(points[idx][0] == j && points[idx][1] == i) {
                idx++;
                while(idx < points.size() && points[idx][0] == j && points[idx][1] == i) idx++;
                stars.append("*");
            } else stars.append(".");
        }
        std::cout<<stars<<"\n";
        answer.push_back(stars);
    }

    return 0;
}

// // line_rows는 2차원 배열 line의 행 길이, line_cols는 2차원 배열 line의 열 길이입니다.
// char** solution(int** line, size_t line_rows, size_t line_cols) {
//     for(int i=0; i<line_rows; i++) {
        
//     }
//     // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
//     char** answer = (char**)malloc(1);
//     return answer;
// }