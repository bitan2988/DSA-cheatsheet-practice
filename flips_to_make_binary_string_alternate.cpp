//https://www.geeksforgeeks.org/number-flips-make-binary-string-alternate/

/*
We can either start the string with zero or with one and can simply return the process which takes the minimum steps.
1. STARTING WITH ZERO --> in this case the even indexes(0 base indexing) will stay zero and odd indexes will flip to ones. Thus total flips will  be equal to 
                         (Zero in odd indexes + One in even indexes)

2.STARTING WITH ONE --> in this case the even indexes(0 base indexing) will stay one and odd indexes will flip to zeroes. Thus total flips will  be equal to 
                         (One in odd indexes + Zero in even indexes)
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int EvenOne = 0, OddOne = 0, EvenZero = 0, OddZero = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            if(i%2)
            {
                OddOne++;
            }
            else
            {
                EvenOne++;
            }
        }
        else
        {
            if(i%2)
            {
                OddZero++;
            }
            else
            {
                EvenZero++;
            }
        }
    }
    cout<<min((OddZero+EvenOne),(EvenZero+OddOne));
    return 0;
}