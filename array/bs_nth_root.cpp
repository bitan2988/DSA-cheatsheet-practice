// We can use binary search to find the n'th root of a number using binary-search
// as the n'th root will lie in the range of 1-n
// We first fix the precision value

#include<bits/stdc++.h>
using namespace std;

double esp = 1e-6; //accuracy till how many decimal place we want the result (here till 5 decimal places so 10^-(5+1)=0.000001)

int main(){

	double x;
	cin>>x;

	double low = 1, high = x, mid;

	// won't use high-low > 1 as terminating condition as a range of values will be lost in that
	// so we will take it to be lesser than the accuracy we wish to set
	while((high-low) > esp){

		mid = (high+low)/2;

		// Doing mid*mid as we are finding the square-root and for n'th root we will simply multiply mid n-times
		if(mid*mid < x)
			low = mid;
		else
			high = mid;
	}

	cout<< setprecision(10) <<low<<endl;
}

// T.C = N*Log(num*(10^precision))    for N'th root of number num with an accuracy of precision