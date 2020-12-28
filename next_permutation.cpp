//Next Permutation
//https://youtu.be/quAS1iydq7U
//start form last element and search for the first elelment where a[i]<a[i+1]--> index1      i->index of an element
//fromm the last search for an elelment which is greater then a[i]-->index2
//swap index1 and index2
//now reverse all the values to the right of index 1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[6]={1,3,5,4,2,9};
    int index1,index2;
    for(int i=4;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            index1 = i;
            break;
        }
    }
    cout<<a[index1]<<"  ";
    for(int j=5;j>=0;j--)
    {
        if(a[j]>a[index1])
        {
            index2 = j;
            break;
        }
    }
    cout<<a[index2]<<endl;
    swap(a[index1],a[index2]);
    cout<<a[index1]<<"  "<<a[index2]<<endl;
    int r;
    r  = (5-index1)/2;
    for(int k=1;k<=r;k++)
    {
        swap(a[index1+k],a[5-k-1]);
    }
    for(int l=0;l<6;l++)
    {
        cout<<a[l]<<" ";
    }

    return 0;

}
