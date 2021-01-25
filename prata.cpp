//https://www.youtube.com/watch?v=0O91QPfA2xk&t=127s
#include <iostream>
#include<algorithm>
using namespace std;
bool isPossible(int cook[],int n,int prata,int time)   //if cook i can finish in the speculated time or not
{
    int num = 0;
    for(int i=0;i<n;i++)   //checking if the chefs together can make it nor not
    {
        int t = 0;
        int next_time = cook[i]; //assigning time taken by cook to make first prate
        while(t + next_time<=time)
        {
            num += 1;
            t += next_time;
            next_time += cook[i];   // time taken to n'th prata will be equal to n*cook[i]
            if(num >= prata)    //made more prata than required
                return true;
        }
    }
    return false;
}
long minTimeNeeded(int cook[],int n,int prata)
{
    int s = 0;
    int e = cook[n-1]*prata*(prata+1)/2;       //as   cook[i](1+2+3+4+5...+p) = cook[i](p*(p+1))/2     as the time to make prata runs in multiple
    int mid,ans = -1;
    while(s<=e)
    {
        mid = (s+e)/2;     //least time taken = 0    and    max time = cook[i](p*(p+1))/2
        if(isPossible(cook,n,prata,mid)){       //if can be make then check for lower time
            e = mid-1;
            ans = mid;
        }
        else
            s = mid + 1;   //if not try adding more and more chefs
    }
    return ans;
}
int main()
{
    int t;
    cout<<"enter test cases : ";
	cin>>t;
    while(t--)
    {
        int prata;
        cout<<"enter prata : ";
		cin>>prata;
        int cook[51];
        int n;
        cout<<"enter no. of cooks: ";
		cin>>n;
		cout<<"enter values ";
        for(int i=0;i<n;i++)
            cin>>cook[i];
        sort(cook,cook+n);
        cout<<minTimeNeeded(cook,n,prata)<<endl;
    }
}
