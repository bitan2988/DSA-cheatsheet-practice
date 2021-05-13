#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];

	int min = *min_element(v.begin(), v.end());   //returns a pointer to the minimum element in the vector
	int max = *max_element(v.begin(), v.end());

	int sum = accumulate(v.begin(), 0);  // 0 is the initial sum that we have to provide

	int ct = count(v.begin(), v.end(), 6);  // Gives the frequency of the value we have passed

	auto emt = find(v.begin(), v.end(), 2);  // Return a pointer to the element if it exists else returns v.end()

	reverse(v.begin(). v.end());  // Reverse the vector or the string
	

}	