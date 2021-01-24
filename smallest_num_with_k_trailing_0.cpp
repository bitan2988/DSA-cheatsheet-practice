//smallest number witth k trailing zeroes in its factorial
//https://www.geeksforgeeks.org/smallest-number-least-n-trailing-zeroes-factorial/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool zcheck(int k, int mid)
{
    int f = 5;
    int count = 0;
    while(f<=mid)
    {
        //count +=mid/f;
        f = f*5;
        cout<<mid<<" ";
    }
    //cout<<count<<"  "<<mid<<"******";
    return (count>=k);
}

int binary(int k)
{
    int low = 0;
    int high = k*5;
    while(low<high)
    {
        int mid = (high+low)/2;
        if(zcheck(k, mid))
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    int k;
    cout<<"enter the number of trailing zeroes : ";
    cin>>k;
    cout<<binary(k);
    return 0;
}