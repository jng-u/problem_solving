#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    // int n = 3;
    // std::vector<std::string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    // int n = 5;
    // std::vector<std::string> words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
    int n = 2;
    std::vector<std::string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
    std::vector<std::string> dict[26];
    int cnt=1;
    char s_char = words[0][0];
    for(auto word : words) {
        if(word[0] != s_char) std::cout<<cnt<<"\n";
        for(auto already : dict[word[0]-'a']) if(already == word) std::cout<<cnt<<"\n";
        dict[word[0]-'a'].push_back(word);
        s_char = word[word.size()-1];
        cnt++;
    }
    return 0;
}
