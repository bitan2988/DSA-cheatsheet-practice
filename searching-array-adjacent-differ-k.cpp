//https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

/*
The above solution can be Optimized using the fact that difference between all adjacent elements is at most k. 
The idea is to start comparing from the leftmost element and find the difference between current array element and x.
 Let this difference be ‘diff’.
 From the given property of array, we always know that x must be at-least ‘diff/k’ away, so instead of searching one by one, we jump ‘diff/k’.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int sea(int a[], int n,int x);

int main()
{
    int n;
    cout<<"Enter the size ";
    cin>>n;
    int a[n],x;
    cout<<"Enter target ";
    cin>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int res;
    res = sea(a,n,x);
    cout<<res;
    return 0;
}

int sea(int a[], int n, int x)
{
    int i = 0;
    int k = abs(a[1]-a[0]);
    while(i<n)
    {
        if(a[i]==x)
        {
            return i;
        }
        else
        {
            i = i + max(1,abs(a[i]-x)/k);
        }
    }
    cout<<"element not present in the array";
    return 0;
}
