/*
	GIVEN JOBS WITH THEIR PROFIT AND DEADLINE WE ARE TO MAXIMISE THE PROFIT CONSIDERING EACH JOB TAKES ONE UNIT TO COMPLETE
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	vector<pair<int, int>> pd = {{5,3}, {10,1}, {15,2}, {20,2}, {1,3}}; //pair<profit, deadline>

	int n;

	sort(pd.begin(), pd.end(), greater<pair<int, int>>());

	for(auto it:pd)
		cout<<it.first<<" "<<it.second<<"\n";


}
