// https://www.geeksforgeeks.org/maximum-product-subset-array/

// We first need to sort the array
// we will take all the positive integers 
// if there is a zero then exclude it
// if there are off number of -ve values ignore the one with least absolute value
// if there are even number of -ve values consider all of them

#include<bits/stdc++.h>
using namespace std;

int max_prod(int arr[], int n){

    int res = 1;
    int i = 0;
    int first_neg = 0;

    sort(arr, arr+n, greater<int>());

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    while(i < n){
        // product of all +ve numbers
        if(arr[i] > 0){      
            res = res*arr[i];
            i++;
        }
        // if zero skip that value
        else if(arr[i]==0)
            i++;
        // store the index of the first -ve value as it will be the min if taken absolute
        else{
            first_neg = i;
            break;
        }
    }

    int neg_prod = 1;
    for(int j=(n-1); j>i; j--){
        // taking product of all -ve value excluding the first negative value
        neg_prod = neg_prod*arr[i];
    }


    // if neg_prod is > 0 that applies there were even number of negative values excluding the first_neg
    if(neg_prod > 0){
        res = res*neg_prod;
    }
    // if neg_prod is < 0 that applies there were odd number of negative values excluding the first_neg and we need to use the first value to make it even or positive
    else
        res = res*neg_prod*arr[first_neg];

    return res;
}

int main(){

    int num[10] = {12,14,16,-1,-2,-3,17,18,10,0};

    std::cout<<max_prod(num, 10);
    cout<<"\n";
}