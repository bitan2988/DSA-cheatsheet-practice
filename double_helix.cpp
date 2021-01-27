//https://www.spoj.com/problems/ANARC05B/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int a[14] = {3,5,7,9,20,25,30,40,55,56,57,60,62,101};
	int b[12] = {1,4,7,11,14,25,44,47,55,57,100,101};
	n = 14;
	m = 12;
	int i=0, j=0, sum1=0, sum2=0, sum=0;
	while(i<n and j<m)
	{
		if(a[i]==b[j])
		{
			sum = sum + a[i] + max(sum1, sum2);    //the number is a bridge so we will only consider it once and take the max sum ot the two arrary
			cout<<"sum1 = "<<sum1<<" sum2 = "<<sum2<<" sum ="<<sum<<endl;    //till that point into account
			sum1 = 0;
			sum2 = 0;
			i++;
			j++;
		}
		else if(a[i]<b[j])   //the upper element is less than lower element so the bridge must be on right of a
		{
			sum1 += a[i];
			i++;
		}
		else
		{
			sum2 += b[j];       //the lower element is lower than upper one so the bridge must be on right of b
			j++;
		}
	}
	int flag = 0;
	//adding the leftover elements in the the sum
	while(j<m)
	{
			flag = 1;
			sum2 +=b[j];
			j++;
	}
	while(i<n)
	{
		flag = 1;
		sum1 +=a[i];
		i++;
	}
	if(flag)
	{
		
		if(a[n-1]==b[m-1])   //if last  element is also a bridge consider it only once
		{
			sum = sum + max(sum1,sum2) - a[n-1];
			cout<<"sum1 = "<<sum1<<" sum2 = "<<sum2<<" sum ="<<sum<<"last element a bridge"<<endl;
		}
		else  //taking max of the two 
		{
			sum = sum + max(sum1, sum2);
			cout<<"sum1 = "<<sum1<<" sum2 = "<<sum2<<" sum ="<<sum<<endl;
		}
	} 
	cout<<"output = "<<sum;
}
