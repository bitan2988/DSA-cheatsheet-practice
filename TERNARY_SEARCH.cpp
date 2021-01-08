/*
JUST LIKE IN BINARY SEARCH TERRENARY SEARCH IS AN DIVIDE AND CONQUEUR  TACHNIQUE IN WHICH WE DIVE THE ARRAY IN THREE PARTS
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int terenary(int r, int l, int target, int nums[])
{
    int mid1, mid2;
    mid1 = l + (r-l)/3;
    mid2 = r - (r-l)/3;
    if (nums[mid1]==target)    //CHECK IF VALUE IS AT MID1
    {
        return mid1;
    }
    else if(nums[mid2]==target)    //OTHERWISE CHECK IF VALUE IS AT MID2
    {
        return mid2;
    }
    else
    {
        if (nums[mid1]>target)      //IF MID1 VALUE>TARGET THEN RETURN THE FIRST 1/3 PORTION
        {
            terenary(mid1,l,target,nums);
        }
        else if(nums[mid2]<target)     //IF MID2<TARGET RETURN THE LAST 1/3 PORTION
        {
            terenary(r,mid2,target,nums);
        }
        else              //ELSE RETURN THE MIDDLE PORTION
        {
            terenary(mid2,mid1,target,nums);
        }
    }

}

int main()
{
    int n,target;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Target = ";
    cin>>target;
    cout<<terenary(n,0,target,nums);
    return 0;
}
