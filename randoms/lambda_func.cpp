#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool is_positive(int x){
	return x > 0;
}

int main(){

	// LAMBDA FUNCTIONS IN C++
	auto sum  = [](int x, int y){return x+y;}; // [](formal_parameter){function_definitio}(values_passed)
	cout<< sum(2,3);


	vector<int> v = {1,2,3,4,5,6,7};
	
	// ALL-OF --> will return TRUE only-if all the elements of the array/vec satisfies a given condition
	cout<< all_of(v.begin(), v.end(), [](int x){return x > 0;});    //using lambda function
	cout<< all_of(v.begin(), v.end(), is_positive);


	// ANY-OF  --> will return TRUE even if a single value satisfies the condition
	cout<< any_of(v.begin(), v.end(), [](int x){return x > 0;});    //using lambda function
	cout<< any_of(v.begin(), v.end(), is_positive);


	// NONE-OF --> will return TRUE only if none of the element satisfy the condition
	cout<< none_of(v.begin(), v.end(), [](int x){return x > 0;});    //using lambda function
	cout<< none_of(v.begin(), v.end(), is_positive);

}