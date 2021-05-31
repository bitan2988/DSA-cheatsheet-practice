// https://www.spoj.com/problems/EKO/      PREDICATE-FUNC : Returns wither TRUE or FALSE
// We can see that the max height is surely to lie in between the range of 0-max_height thus we can use BS to search for it
// Moreover we here have a mono-tonic predicate function and thus BS can be used

#include<iostream>
using namespace std;

bool enough_wood(int a[], int n, int wood, int height){

	int curr_wood = 0;

	for(int i=0; i<n; i++){
		if(a[i]>height)
			curr_wood += (a[i]-height);
	}

	if(curr_wood >= wood)
		return true;
	else
		return false;

};


int main(){

	int a[] = {8, 9, 4, 3, 5, 6, 2};
	int wood;
	cin>>wood;
	int n = sizeof(a)/sizeof(a[0]);	

	int low = 0;
	int high = a[0];
	for(int i=1; i<n; i++)
		if(a[i]>high)
			high = a[i];

	int mid;

	while(low < high){

		mid = (low+high)/2;

		if(enough_wood(a, n, wood, mid))
			low = mid+1;
		else
			high = mid;
	}

	cout<<"max height = "<<mid;
}

