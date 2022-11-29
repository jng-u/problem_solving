/**
 * 백준 5430번
 * AC 
 * Queue, Deque
 */
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--){
        string p;
        cin>>p;
        
        int n;
        cin>>n;

        list<int> x;
        string xstr;
        cin>>xstr;
        xstr = xstr.substr(1, xstr.size()-2);
        int idx=0;
        while(!xstr.empty()){
            int len=0;
            while(xstr[idx] != ',') {
                len++;
                idx++;
                if(idx==xstr.size()) break;
            }
            x.push_back(atoi(xstr.substr(idx-len, len).c_str()));
            if(idx==xstr.size()) break;
            idx++;
        }
        
        bool rflag=false;
        string ans = "";
        for(int i=0; i<p.size(); i++){
            if(p[i]=='R'){
                rflag = !rflag;
            } else if(p[i]=='D'){
                if(x.empty()){
                    ans = "error";
                    break;
                }
                if(!rflag) x.pop_front();
                else x.pop_back();
            }
        }
        // if(rflag) x.reverse();

        if(ans.empty()){
            stringstream ss;        
            ss<<"[";
            if(rflag) for(auto i = x.rbegin(); i!=x.rend(); i++) ss<<*i<<",";
            else for(auto i = x.begin(); i!=x.end(); i++) ss<<*i<<",";
            ans = ss.str();
            if(ans[ans.size()-1]==',') ans[ans.size()-1] = ']';
            else ans.append("]");
        } else {
        }
        cout<<ans<<"\n";
    }


    return 0;
}