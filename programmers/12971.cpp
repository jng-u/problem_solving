#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    // std::vector<int> sticker = {14, 6, 5, 11, 3, 9, 2, 10};
    std::vector<int> sticker = {1, 3, 2, 5, 4};
    
    int answer = 0;

    int length = sticker.size();
    std::vector<int> case0, case1, case2;
    if (length == 1) {
        answer = sticker[0];
    } else if (length == 2) {
        answer = (sticker[0] > sticker[1])? sticker[0] : sticker[1];
    } else {
        case0.resize(length-1);
        case0[0] = sticker[0]; case0[1] = 0; case0[2] = sticker[0]+sticker[2];
        case1.resize(length);
        case1[0] = 0; case1[1] = sticker[1]; case1[2] = sticker[2];
        for (int i=3; i<length; i++) {
            if(i<length-1) case0[i] = sticker[i] + ((case0[i-3] > case0[i-2])? case0[i-3] : case0[i-2]);
            case1[i] = sticker[i] + ((case1[i-3] > case1[i-2])? case1[i-3] : case1[i-2]);
        }
        answer = (case0[length-2] > case0[length-3])? case0[length-2] : case0[length-3];
        answer = (answer > case1[length-2])? answer : case1[length-2];
        answer = (answer > case1[length-1])? answer : case1[length-1];
    }


    std::cout<<answer<<"\n";

    return 0;
}
