// https://www.spoj.com/problems/GERGOVIA/
// since we have to one work every time and it is given the total sum of the array = 0
// we can conclude that every wine that needs to be solt must be bought and that it ahve to travel
// to the distance. Thus what we do is we keep the wime moving ahead every time and keep a track of the sum
// since we know that it will definitely travel the last index and that work done will remain same.

#include<iostream>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(1){
		int n;
		cin >> n;
		if(n == 0)
			break;
		int arr[n];

		for(int i=0; i<n; i++)
			cin>>arr[i];

		ll ans = 0;
		for(int i = 1;i < n; i++){
			arr[i] += arr[i-1];
			ans += abs(arr[i-1]);
		}
		cout << ans << endl;
	}    
}