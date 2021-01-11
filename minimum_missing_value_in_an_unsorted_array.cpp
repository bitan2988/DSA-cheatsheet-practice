//https://www.youtube.com/watch?v=-lfHWWMmXXM
//O(1) extra space

//APPROACH 1  -->fails for zero

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void app(int n, int a[]);

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k = 0, val;
    while(k<n)
    {
        if(a[k]>=n or a[k]<0)
        {
            k++;
        }
        else
        {
            val = a[k];
            a[val] = a[val]*(-1);
            k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>0 and a[i]<n)
        {
            cout<<"\nValue is "<<i<<endl;
        }
    }
    app(n,a);
    return 0;
}


//APPROACH 2 -->placing value at their index

void app(int n, int a[])
{
    int i = 0;
    while(i<n)
    {
        if(a[i]<0 or a[i]>=n or a[i]==i)
        {
            i++;
        }
        else
        {
            swap(a[i],a[a[i]]);
        }
    }
    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
    }
    for(int k=0;k<n;k++)
    {
        if(a[k]!=k)
        {
            cout<<"\nresult = "<<k;
        }
    }

}

//-1 0 3 1 4