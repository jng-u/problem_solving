#include <stdio.h>
#include <vector>
using namespace std;

class Piece{
public:
	Piece(int prime_num){
		this->prime_num = prime_num;
		f_num = prime_num/10;
		s_num = prime_num%10;
	};

	int prime_num;
	int f_num, s_num;
};

int main(){
	int piece_num;
	scanf("%d", &piece_num);

	vector<Piece> pieces;
	int tmp;
	for(int i=0; i<piece_num; i++){
		scanf("%d", &tmp);
		pieces.push_back(Piece(tmp));
	}
	tmp=0;

	int number[10];
	for(int i=0; i<10; i++){
		for(int j=0; j<pieces.size(); j++){
			if(i==pieces[j].f_num || i==pieces[j].s_num) tmp++;
		}
		number[i]=tmp;
		tmp=0;
	}

	int ans;
	for(int i=0; i<10; i++){
		if(number[i]/2 > 1){
			if((number[i]/2)%2==1){
				ans += number[i]/2;
			} else if((number[i]/2)%2==0){
				ans += number[i]/2 + 1;
			}
		} else {
			ans=1;
		}
	}

	printf("%d\n", ans);

	return 0;
}