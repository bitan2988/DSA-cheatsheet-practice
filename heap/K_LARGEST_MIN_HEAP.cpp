// K'th LARGEST ELEMENT
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int a[10] = {1,9,5,7,2,6,2,3,4,8};
    int k = 6;
    for(int i=0;i<10;i++){
        if(min_heap.size()==k){
            min_heap.pop();
        }
        min_heap.push(a[i]);
    }
    /*while(min_heap.empty()==false){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }*/
    cout<<endl;
    cout<<min_heap.top();
    return 0;
}
// since we have to find the k'th largest element so we need the remove the values smaller than it as they wont make the cut
// in min heap the value at top is the smallest so we simply remove it 
