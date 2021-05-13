//FRACTIONAL KNAPSACK

#include<bits/stdc++.h>
using namespace std;

int main(){

	int knapsack = 15;
	vector<pair<int, int>> pw = {{60,5}, {20,2}, {10,5}, {60,15}};   //pair<prfit, weight>
	vector<pair<float, int>> profit_per_kg;  //pair<profir/weight, index>

	for(int i=0; i<pw.size(); i++){
		profit_per_kg.push_back({pw[i].first/pw[i].second, i});
	}

	for(auto it:pw)
		cout<<it.first<<" "<<it.second<<endl;

	cout<<endl;

	sort(profit_per_kg.begin(), profit_per_kg.end(), greater<pair<float, int>>());


	for(auto it:profit_per_kg)
		cout<<it.first<<" ";

	cout<<endl;

	int curr_weight = 0;
	int i = 0;

	while(curr_weight < knapsack && i < pw.size()){

		if(pw[profit_per_kg[i].second].second <= (knapsack - curr_weight)){
			cout<<pw[profit_per_kg[i].second].first<<"+";
			curr_weight += pw[profit_per_kg[i].second].second;
			i++;
		}

		else{
			int diff = knapsack - curr_weight;

			cout<<profit_per_kg[i].first*diff;

			curr_weight = knapsack;
			break;
		}
	}
	cout<<endl;

}
/*
struct Item{
    int value;
    int weight;
};

bool cmp(struct Item a, struct Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }  
class Solution
{
    public:
     
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        
        int curWeight = 0; // Current weight in knapsack
        double finalvalue = 0.0; // Result (value in Knapsack)
    
        // Looping through all Items
        for (int i = 0; i < n; i++) {
            // If adding Item won't overflow, add it completely
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
    
            // If we can't add current Item, add fractional part
            // of it
            else {
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
                break;
            }
        }

        return finalvalue;
    }
 
};*/
