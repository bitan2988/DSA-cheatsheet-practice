// https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/
// Upon inspecting we can find that the max absolute sum of difference happens when the aray is of format
// even indexes has the least amount of values in ascending manner
// odd indexes store all the greastest values in descending manner

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll sum(int a[], int n){

    ll sum = 0;
    for(int i=0; i<n-1; i++)
        sum += abs(a[i]-a[i+1]);
    sum += abs(a[n-1]-a[0]); 

    return sum;
} 

int main(){

    int a[]={1, 2, 4, 8};
    int n = sizeof(a)/sizeof(a[0]);

    sort(a, a+n);
    int temp[n];
    int low = 0, high = n-1;

    for(int i=0; i<n; i++){

        if(i&1){
            temp[i] = a[high];
            high--;
        }
        else{
            temp[i] = a[low];
            low++;
        }
    }
    /*     ALTERNATE WAY OF DOING THIS SWAP
    vector<int> finalSequence;
    for (int i = 0; i < n / 2; ++i) {
        finalSequence.push_back(a[i]);
        finalSequence.push_back(a[n - i - 1]);

    if (n % 2 != 0)
        finalSequence.push_back(a[n/2]);
    }
    */
    for(int i=0; i<n; i++)
        cout<<temp[i]<<" ";

    cout<<"\n";
    cout<<sum(temp, n)<<endl;
}