#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> a = {-16,30,27,65,-2,-92,58,-71,-68,-61,-33};
    // std::vector<int> a = {9,-1,-5};
    // std::vector<int> a = {-5,-1,9};
    int len = a.size();

    if (len < 3) std::cout<<len;

    int p=1;
    while(a[p-1] > a[p]) p++;
    int q=len-2;
    while(a[q+1] > a[q]) q--;
    int min_idx=0;
    for(int i=0; i<len; i++) min_idx = (a[i]<a[min_idx])? i : min_idx;
    
    std::cout<<p<<" "<<len-q-1<<'\n';
    int cnt = (p==len || q==-1)? len:p+len-q-1;
    if(p<=min_idx && min_idx<=q) cnt += 1;

    std::cout<<cnt<<'\n';
    return 0;
}
