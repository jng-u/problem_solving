/**
 * 백준 9251번
 * LCS
 * Dynamic Programming
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string A, B;
    cin>>A>>B;

    int arr[1001][1001] = {0, };

    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            // arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            // if(A[i-1] == B[j-1] && 1 > arr[i][j] - min(arr[i-1][j], arr[i][j-1])) arr[i][j]++;
            if(A[i-1] == B[j-1]) arr[i][j] = arr[i-1][j-1]+1;
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    // for(int i=1; i<=A.size(); i++){
    //     for(int j=1; j<=B.size(); j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<arr[A.size()][B.size()]<<"\n";

    return 0;
}
