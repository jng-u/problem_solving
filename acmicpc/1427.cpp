/**
 * 백준 1427번
 * 소트 인사이드
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string number;
    cin>>number;

    int count[10] = {0, };
    // int *arr = new int[number.size()];
    for(int i=0; i<number.size(); i++){
        // arr[i] = number[i]-'0';
        count[number[i]-'0']++;
    }
    
    for(int i=9; i>=0; i--){
        while(count[i]--){
            cout<<i;
        }
    }
    cout<<"\n";
    
    
    return 0;
}
