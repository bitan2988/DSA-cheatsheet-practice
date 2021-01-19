#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[9] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
	int target = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	int start = 0;
	int end = n;
	int mid;
	/*
	1) Find middle point mid = (l + h)/2
	2) If key is present at middle point, return mid.
	3) Else If arr[l..mid] is sorted
    	a) If key to be searched lies in range from arr[l]
       to arr[mid], recur for arr[l..mid].
    	b) Else recur for arr[mid+1..h]
	4) Else (arr[mid+1..h] must be sorted)
    	a) If key to be searched lies in range from arr[mid+1]
       	   to arr[h], recur for arr[mid+1..h].
    	b) Else recur for arr[l..mid]
	*/
	while(start<=end)
	{
		mid =(start+end)/2;
		if (arr[mid]==target)
		{
			cout<<"value at index "<<mid;
			break;
		}
		else if(arr[start]<=arr[mid])
		{
			if(target>=arr[start] and target<=arr[mid-1])
			{
				end = mid-1;
			}
			else
			{
				start = mid+1;
			}
		}
		else
		{
			if (target>arr[mid+1] and target<=arr[end])
			{
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
	}
	return 0;
}
