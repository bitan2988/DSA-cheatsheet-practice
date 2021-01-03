//https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/

//Roman Numbers is a decreasing series if s[i+1]>s[i] then we have to subtract s[i] from the numerical value  of s[i+1]

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int rton (char c)
{
    if(c=='I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
 
    return -1;
}

int main()
{
    string s;
    cin>>s;
    int l = s.length();
    int res = 0;
 
    // Traverse given input
    for (int i=0; i<l; i++) 
    {
        // Getting value of symbol s[i]
        int s1 = rton(s[i]);
 
        if (i+1<l) 
        {
            // Getting value of symbol s[i+1]
            int s2 = rton(s[i+1]);
 
            // Comparing both values
            if (s1>=s2) 
            {
                res +=s1;
            }
            else
            {
                // Value of current symbol is less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else  //for last  element
        {
            res = res + s1;
        }
    }
    cout<<res;
    return 0;

}