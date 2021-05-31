// We have to find an element in an infinite long sorted array where the length of the array is not given and we cant use any inbuilt func to find it
// The idea is to look for the element over a particular range 
// We wont use a constant range to find the element instead use an exponentially growing range to make time = O(logN)
// range grows exponentially in powers of two 2,4,8,16,32,64,128...

#include<iostream>
#include<vector>
using namespace std;

int bs_no_high(vector<int> arr, int num){

	int low = 0;
	int range = 1;

	// Finding a range in which the element lies
	while(arr[range] < num){

		low = range;
		range = range*2;
	}

	// Now we have a proper range with low and high indexes in which the element lie
	// So we can use normal binary-search algo to find it
	int high = range;
	int mid;
	while(low < high){

		mid = (low+high)/2;

		if(arr[mid]==num)
			return mid;

		if(arr[mid]>num)
			high = mid-1;
		else
			low = mid;
	}

	return low;
}

int main(){

	vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

	int num = 8;
	cout<<bs_no_high(arr, num);
}