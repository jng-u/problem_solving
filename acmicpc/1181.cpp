/**
 * 백준 1181번
 * 단어 정렬 
 */

#include <iostream>
using namespace std;

bool operator <=(string &a, string &b){
    if(a.length() < b.length()) return true;
    else if(a.length() == b.length()){
        for(int i=0; i<a.length(); i++){
            if(a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
        return true;
    }
    else return false;
}

bool operator >=(string &a, string &b){
    if(a.length() > b.length()) return true;
    else if(a.length() == b.length()){
        for(int i=0; i<a.length(); i++){
            if(a[i] < b[i]) return false;
        }
        return true;
    }
    else return false;
}

void swap(string &a, string &b){
    string tmp = a;
    a = b;
    b = tmp;
}

void merge(string *arr, const int &s, const int &e){
    int len = e-s+1;
    if(len==1) return ;
    int m = (s+e)/2;
    merge(arr, s, m);
    merge(arr, m+1, e);

    string *tmp = new string[len];
    int cnt=0;
    int l=s, r=m+1;
    while(true){
        if(arr[l]<=arr[r]) {
            tmp[cnt] = arr[l];
            cnt++; l++;
            if(l>m){
                while(r<=e){
                    tmp[cnt] = arr[r];
                    cnt++; r++;
                }
                break;
            }
        } else {
            tmp[cnt] = arr[r];
            cnt++; r++;
            if(r>e){
                while(l<=m){
                    tmp[cnt] = arr[l];
                    cnt++; l++;
                }
                break;
            }
        }
    }
    for(int i=0; i<len; i++){
        arr[s+i] = tmp[i];
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    string *words = new string[N];
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        words[i] = str;
        for(int j=0; j<i; j++){
            if(words[j] == words[i]) {
                i--;
                N--;
                break;
            }
        }
    }

    merge(words, 0, N-1);

    for(int i=0; i<N; i++){
        cout<<words[i]<<"\n";
    }
    
    return 0;
}
