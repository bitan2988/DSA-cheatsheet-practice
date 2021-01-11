//https://www.youtube.com/watch?v=LPFhl65R7ww&feature=youtu.be
/*
partitionx + partitiony = (len(x)+len(y)+1)/2
partitionx = (start + end)/2
partitiony = ((x+y+1)/2) - partitionx

search till:
    maxLeftX <= maxRightY
    maxLeftY <= maxRightX
else if:
    maxLeftX > maxRightY
    --> Move towards left in X
else:
    -->move towards right in X

By this method we are basically sorting the middle portion of the  array
around where the median would have been calculated normally
*/
#include<iostream>
using namespace std;

int max(int a, int b)
{
    return a>=b?a : b;
}

int min(int a, int b)
{
    return a<=b?a : b;
}



int median(int start, int end, int a[], int b[],int n,int m)
{
    int px, py;
    px = (start+end)/2;
    py = ((n+m+1)/2) - px;
    if(a[px-1]<=b[py] and b[py-1]<=a[px])
    {
        if ((n+m)%2)
        {
            cout<<max(a[px-1],b[py-1]);
        }
        else
        {
            cout<<(max(a[px-1],b[py-1]),min(a[px],b[py]))/2;
        }
        
    }
    else if(a[px-1]>b[py])
    {
        return median(start,end+1,a,b,n,m);
    }
    else
    {
        return median(start+1,end,a,b,n,m);
    }
}

int main()
{
    int m,n;
    cout<<"enter size of array a and b : ";
    cin>>n>>m;
    int a[n], b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int ans;
    if(n>m)   //binary search on smallest array
    {
        median(0,m,a,b,n,m);
    }
    else
    {
        median(0,n,a,b,n,m);
    }
    
}