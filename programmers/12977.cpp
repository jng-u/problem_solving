#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<bool> prime_table(3000, true);
    prime_table[0] = prime_table[1] = false;
    for(int i=2; i<ceil(sqrt(prime_table.size())); i++) {
        int j=1;
        if(!prime_table[i*j++]) continue;
        while(i*j < prime_table.size()) prime_table[i*j++] = false;
    }

    int answer = 0;
    for(int i=0; i<nums.size()-2; i++) 
        for(int j=i+1; j<nums.size()-1; j++) 
            for(int k=j+1; k<nums.size(); k++) 
                if(prime_table[nums[i]+nums[j]+nums[k]]) answer++;

    return 0;
}
