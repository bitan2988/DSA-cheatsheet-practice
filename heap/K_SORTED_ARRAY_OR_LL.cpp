//K-sorted array/linked list
//https://www.youtube.com/watch?v=dYfM6J1y0mU
//since for an index its original value in the sorted array is at most k distance away in the input array, thus we create a min heap of size k
//as in that heap of sixe k the correct value must be present at top as the value is only k distance away in the input array
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int a[7] = {6, 5, 3, 2, 8, 10, 9};
    vector<int> sa;   //sorted array
    int n = sizeof(a)/sizeof(a[0]);
    int k;
    cout<<"enter k : ";
    cin>>k;
    for(int i=0;i<n;i++){
        if(min_heap.size()>=k+1){
            sa.push_back(min_heap.top());
            min_heap.pop();
        }
        min_heap.push(a[i]);
    }
    while(min_heap.empty()==false){
        sa.push_back(min_heap.top());
        min_heap.pop();
    }
    for(auto it = sa.begin(); it != sa.end(); it++)
		cout << *(it) << " ";
}