#include <iostream>
#include <vector>



int main(int argc, char const *argv[])
{
    // int N = 5;
    // int K = 3;
    // std::vector<std::vector<int>> road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    int N = 6;
    int K = 4;
    std::vector<std::vector<int>> road = {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};

    int answer = 0;
    std::vector<std::vector<int>> graph(N, std::vector<int>(N, 0));
    std::vector<std::vector<bool>> check(N, std::vector<bool>(N, false));

    for (auto line : road) {
        if (graph[line[0]-1][line[1]-1] == 0) graph[line[0]-1][line[1]-1] = line[2];
        else graph[line[0]-1][line[1]-1] = (graph[line[0]-1][line[1]-1] < line[2])? graph[line[0]-1][line[1]-1] : line[2];
        graph[line[1]-1][line[0]-1] = graph[line[0]-1][line[1]-1];
        if (line[2] == 1) check[line[0]-1][line[1]-1] = check[line[1]-1][line[0]-1] = true;
    }

    for (int n=0; n<N-1; n++){
        for (int s=0; s<N-1; s++) {
            for (int e=s+1; e<N; e++) {
                int time = graph[s][e];
                
                for (int i=0; i<N; i++) {
                    if (i==s || i==e) continue;
                    int t1 = graph[s][i];
                    int t2 = graph[i][e];
                    if (t1==0 || t2==0) continue;
                    
                    if (time == 0) time = t1+t2;
                    else time = (time < t1+t2)? time : t1+t2;
                }

                if (time == graph[s][e]) continue;
                else graph[s][e] = graph[e][s] = time;
            }
        }
    }

    for (int i=0; i<N; i++)
        if (graph[0][i] <= K) answer++;


    std::cout<<answer<<"\n";

    return 0;
}
