// https://www.thealgorists.com/Algo/TrappingRain  --> Lower Envelope --> https://www.youtube.com/watch?v=XqTBrQYYUcc

// We will use stack based approach for this case
// Till it,s a non-increasing in stack insert values as soon as  we find a value greater than(x) top value we basically get a container
// at this point we pop values until we get a value gretaer than x we again start inserting in stack

#include<iostream>
#include<stack>
using namespacce std;

int main(){

	stack<int> st;
	int area = 0;
	int n;
	cin>>n;
	int arr[n];

	for(int i=0; i<n; i++)
		cin>>arr[i];

	for(int i=0; i<n; i++){

		if(st.top() < a[i]){

			if(a[i] > st.top()){
				while(st.top() <= a[i]){
					area += (a[i]-st.top());
					st.pop()
				}
			}
			st.insert(a[i]);
		}
	}
	cout<<area;
}