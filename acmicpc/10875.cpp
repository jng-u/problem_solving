#include <iostream>
#include <cmath>
using namespace std;

int map_size;
int history[1000][5];	//start x, start y, end x, end y, direction

int validation_die(int curr_count);

int main(void){
	int rotate_count;
	int x_pos=0, y_pos=0;
	int time_count=0;
	int vec[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};	//R U L D//L:vec[+][], R:vec[-]
	int direction_mode=0;
	cin>>map_size;
	cin>>rotate_count;

	for(int i=0; i<rotate_count; i++){
		int t;
		char direction;
		cin>>t>>direction;

		history[i][0]=x_pos; 
		history[i][1]=y_pos;
		x_pos+=t*vec[direction_mode][0];
		y_pos+=t*vec[direction_mode][1];
		history[i][2]=x_pos;
		history[i][3]=y_pos;
		history[i][4]=direction_mode;
		
		time_count+=t;
		if(validation_die(i)!=-1){
			cout<<time_count-validation_die(i)+1;
			return 0;
		}

		if(direction=='L') {
			direction_mode++;
			if(direction_mode==4) direction_mode=0;
		} 
		else if(direction=='R') {
			direction_mode--;	
			if(direction_mode==-1) direction_mode=3;
		} 
	}
	return 0;
}

int validation_die(int curr_count){
	int prev_x_pos=history[curr_count][0], 
		prev_y_pos=history[curr_count][1],
		x_pos=history[curr_count][2],
		y_pos=history[curr_count][3];
	if(abs(x_pos)>map_size) return abs(x_pos)-map_size-1;
	if(abs(y_pos)>map_size) return abs(y_pos)-map_size-1;
	for(int i=0; i<curr_count; i++){
		int tpx=history[i][0],
			tpy=history[i][1],
			tx=history[i][2],
			ty=history[i][3],
			td=history[i][4];
			if(td==0){
				
			} else if(td==1){

			} else if(td==2){
				
			} else if(td==3){
				
			}

	}
	return -1;
}
