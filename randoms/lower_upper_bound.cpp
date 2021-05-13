/*
	ARRAYS/VECTOR NEEDS TO BE SORTED BEFORE USE OF THIS FUNCTIONS
		if sorted then they will use O(logN) time
		else will use O(N) time
	BASICALLY ALLOWS US TO USE BINARY SEARCH USING THESE FUNCTIONS


		LOWER BOUND --> will either find the given element( if present in the array ) or else the next element greater to it

		UPPER BOUND --> will always the next  greatest value even if the number is present
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[9] = {9, 4, 2, 3, 1, 7, 6, 2, 8};

	int n = sizeof(a)/sizeof(a[0]);

	sort(a, a+n);

	// THEY RETURN LOCATION i.e POINTERS FOR ARRAY AND ITERATORS FOR VECTORS

	int *pt = lower_bound(a, a+n, 4);
	//        lower_boumd(starting address, ending address's next, val to be found)
	if(pt == a+n){
		cout<<"NOT FOUND";
		return 0;
	}
	cout<<*pt;

	pt = upper_bound(a, a+n, 5);
	cout<<" "<<*pt<<endl;

	//FOR SETS AND MAPS PASSING IN NORMAL MANNER USES O(n) TIME, THUS USE IN BELOW MANNER FOR O(logN)
	set<int> s;
	auto it = set.lower_bound(5) //s.lower_bound(value)

	//FOR MAP LOWER/UPPER BOUND ONLY WORKS FOR KEYS
	map<int, int> m;
	auto it = m.lower_bound(5);
}




