/**
 * 백준 9471번
 * 피사노 주기
 * fibonacci
 */
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int P;
    cin>>P;
    while(P--){
        long long ans=0;
        
        int N, M;
        cin>>N>>M;

        int c = M;
        if(c>100 && c%10==0){
            int n=0;
            while(c!=1){
                n++;
                if(c%10==0) c/=10;
                else break;
            }
            if(c==1){
                ans = 15*M/10;
                cout<<N<<" "<<ans<<"\n";
                continue;
            }
        }

        c = M;
        if(c%5==0){
            int n=0;
            while(c!=1){
                n++;
                if(c%5==0) c/=5;
                else break;
            }
            if(c==1){
                ans = 4*M;
                cout<<N<<" "<<ans<<"\n";
                continue;
            } else if(c==2){
                ans = 6*M;
                cout<<N<<" "<<ans<<"\n";
                continue;
            }
        }

        c = M;
        if(c%2==0){
            int n=0;
            while(c!=1){
                n++;
                if(c%2==0) c/=2;
                else break;
            }
            if(c==1){
                ans = 3*M/2;
                cout<<N<<" "<<ans<<"\n";
                continue;
            }
        }

        vector<int> fibo;
        fibo.push_back(0);
        fibo.push_back(1%M);
        fibo.push_back(1%M);
        fibo.push_back(2%M);
        fibo.push_back(3%M);
        for(long long i=4; i<=(long long)M*M-1; i+=2){
            bool flag = true;
            for(long long j=1; j<=i; j++){
                int size = fibo.size();
                while(size<j+i+1){
                    fibo.push_back((fibo.at(size-1)+fibo.at(size-2))%M);
                    size = fibo.size();
                } 
                if(fibo[j] != fibo[j+i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = i;
                break;
            }
        }
        cout<<N<<" "<<ans<<"\n";
    }

    return 0;
}
