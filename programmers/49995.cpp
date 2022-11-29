#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> cookie = {1, 2};
    std::vector<std::vector<int>> sum_table;
    sum_table.resize(cookie.size());
    for(int i=0; i<sum_table.size(); i++) sum_table[i].resize(cookie.size());

    sum_table[0][0] = cookie[0];
    for(int i=0; i<sum_table.size(); i++) {
        for(int j=i; j<sum_table.size(); j++) {
            if (i == 0 && j != 0) sum_table[i][j] = sum_table[i][j-1] + cookie[j];
            else if(i != 0) sum_table[i][j] = sum_table[i-1][j] - sum_table[i-1][i-1];
        }
    }

    int max = 0;
    for(int i=0; i<cookie.size()-1; i++) {
        int idxc=0, idxr=sum_table.size()-1;
        int val=0;
        while(idxc != i+1 && idxr != i) {
            if(sum_table[idxc][i] == sum_table[i+1][idxr]) {
                val = sum_table[idxc][i];
                break;
            }
            if(sum_table[idxc][i] < sum_table[i+1][idxr]) idxr--;
            else idxc++;
        }
        max = (max > val)? max : val;
    }
    std::cout<<max<<"\n";

    return 0;
}
