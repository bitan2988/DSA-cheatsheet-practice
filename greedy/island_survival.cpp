//https://www.geeksforgeeks.org/survival/
#include<bits/stdc++.h>
using namespace std;

bool survive(int s, int n, int m){
    
    if(n < m)
        return false;

    else{
        if((((n-m)*6) < m) && n >= 7)    // since the shop remains closed on Sundays thus we have to save enough from the rest six days that it cover up for Sunday
            return false;

        return true;
    }
}

int main(int argc, char** argv){

    int s = atoi(argv[1]);    // no. of days to survive
    int n = atoi(argv[2]);   // max amount of food we can buy in a single day
    int m = atoi(argv[3]);   // amount of food needed per day

    if(survive(s, n, m))
        std::cout<<"Survive!!! \n";
    else
        std::cout<<"Won't survive \n";
}