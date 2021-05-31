// https://www.spoj.com/problems/DEFKIN/

#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b){

	return a.second < b.second;
}

int main(){

	int t;
	cin>>t;
	while(t--){

		int row, col, n;
		cin>>row>>col>>n;

		vector<pair<int, int>> arr;

		//cout<<row<<" "<<col<<" "<<n<<endl;

		for(int i=0; i<n; i++){

			int f,s;
			cin>>f>>s;
			arr.push_back({f, s});
		}

		sort(arr.begin(), arr.end());

/*		for(auto it : arr)
			cout<<it.first<<" "<<it.second<<endl;*/

		int length, max_length;

		for(int i=1; i<n; i++){

			length = arr[i].first - arr[i-1].first;

			max_length = (length > max_length) ? length : max_length;
		}

		sort(arr.begin(), arr.end(), comparator);

		/*for(auto it : arr)
			cout<<it.first<<" "<<it.second<<endl;*/

		int height, max_height;

		for(int i=1; i<n; i++){

			height = arr[i].second - arr[i-1].second;

			max_height = (height > max_height) ? height : max_height;
		}

		int area;

		area = (max_height - 2) * (max_length - 2);

		cout<<area;
	}
}