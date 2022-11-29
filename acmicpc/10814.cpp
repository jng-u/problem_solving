/**
 * 백준 10814번
 * 나이순 정렬
 */

#include <iostream>
using namespace std;

struct member{
    int age;
    string name;
};

bool operator <=(member &a, member &b){
    if(a.age <= b.age) return true;
    else return false;
}

bool operator >=(member &a, member &b){
    if(a.age >= b.age) return true;
    else return false;
}

void swap(member &a, member &b){
    member tmp = a;
    a = b;
    b = tmp;
}

void merge(member *arr, const int &s, const int &e){
    int len = e-s+1;
    if(len==1) return ;
    int m = (s+e)/2;
    merge(arr, s, m);
    merge(arr, m+1, e);

    member *tmp = new member[len];
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

    member *members = new member[N];
    for(int i=0; i<N; i++){
        int n;
        string str;
        cin>>n>>str;
        members[i].age = n;
        members[i].name = str;
    }

    merge(members, 0, N-1);

    for(int i=0; i<N; i++){
        cout<<members[i].age<<" "<<members[i].name<<"\n";
    }
    
    return 0;
}
