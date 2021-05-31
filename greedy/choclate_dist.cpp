// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
// We can observe that we have to take m consecutive values and that the diff b/w the 
// a[i] and a[i+m] element should be minimum while iterating over the array

#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main(){

	vector<ll> a;
	ll n = sizeof(a)/sizeof(a[0]);
	ll min_diff = INT_MAX, diff;

	for(ll i=0; i < n-m-1; i++){

		diff = a[i+m-1] - a[i];

		min_diff = (min_diff < diff) ? min_diff : diff;
	}

	cout<<"Minimum difference = "<<min_diff;
}