//MOOORE's VOTING ALGO TO FIND THE MAJORITY ELEMENT
// youtube.com/watch?v=n5QY3x_GNDg
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {1,3,3,3,3,3,1,3,2,1};
    int count = 0, ele = a[0];
    for(int i=0;i<10;i++)   //find the majority element
    {
        if(a[i]!=ele)
        {
            count--;
        }
        if(count==0)
        {
            ele = a[i];
            count++;
        }
        if(ele==a[i])
        {
            count++;
        }
    }
    //checking if the majority has appeared more than n/2 times
    count = 0;
    for(int i=0;i<10;i++)
    {
        if(a[i]==ele)
        {
            count++;
        }
    }
    if(count>((sizeof(a)/sizeof(a[0]))/2))
    {
        cout<<ele;
    }
    else
    {
        cout<<"no majority element found";
    }
    return 0;
}