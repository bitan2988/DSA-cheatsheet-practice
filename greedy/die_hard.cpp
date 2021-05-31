// https://www.spoj.com/problems/DIEHARD/
// check if it's possible to move to any of the element else quit

#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int die(){

	pair<int, int> air = {3, 2};
	pair<int, int> water = {-5, -10};
	pair<int, int> fire = {-20, 5};

	pair<int, int> curr;

	cin>>curr.first>>curr.second;

	if(curr.first <= 0 and curr.second <= 0)
		return 0;
	else{

		// Since first move will always be air
		curr.first += air.first;
		curr.second += air.second;
		int time = 1;

		while(curr.first > 0 and curr.second > 0){

			if((curr.first - water.first) > 0 and (curr.second - water.second) > 0){

				curr.first += -2;  // also considering that in next move it will again go bach to air
				curr.second += -8;  // thus resultant will be curr+water+air
				time += 2;
			}
			else if((curr.first - fire.first) > 0 and (curr.second - fire.second) > 0){

				curr.first += -17;  // also considering that in next move it will again go bach to air
				curr.second += 7;  // thus resultant will be curr+fire+air
				time += 2;
			}
		}

		return time;
	}	
}

int main(){

	int res = die();

	cout<<"The time for which the character will survive is"<<res;
}