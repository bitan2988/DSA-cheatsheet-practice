/*      map<key, vector<datatype>> map_of_vector;
		OR
		map<vector<datatype>, key> map_of_vector;				*/


#include<bits/stdc++.h>
using namespace std;

int main(){

	map<int, vector<int>> mov;

	vector<int> data1{1, 2, 3};
	mov[1] = data1;

	map<int, vector<int>> :: iterator it;

	/*for(it=mov.begin(); it!=mov.end(); i++){
		cout<<it->first<<" "<<it->second;
	}*/

}
