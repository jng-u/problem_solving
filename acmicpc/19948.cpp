/**
 * 백준 19948번
 * 음유시인 영재
 * 2020 IGRUS Newbie Programming Contest E번
 */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string poem;
    getline(cin, poem);
    int spacible_cnt;
    cin>>spacible_cnt;
    int alphabet_cnt[26] = {0, };
    for(int i=0; i<26; i++) cin>>alphabet_cnt[i];

    string title="";
    bool title_flag = true;
    for(int i=0; i<poem.size(); i++){
        if(poem[i] == ' '){
            if(poem[i] != poem[i-1])
                spacible_cnt--;
            if(spacible_cnt<0){
                cout<<"-1\n";
                return 0;
            }
            title_flag = true;
        } else {
            if(title_flag) {
                title.push_back(toupper(poem[i]));
                title_flag = false;

                alphabet_cnt[toupper(poem[i])-'A']--;
            }

            int p;
            if(isupper(poem[i])) p = poem[i]-'A';
            else p = poem[i]-'a';
            if(poem[i] != poem[i-1] || i==0)
                alphabet_cnt[p]--;
            if(alphabet_cnt[p]<0){
                cout<<"-1\n";
                return 0;
            }
        }  
    }
    
    cout<<title<<"\n";

    return 0;
}
