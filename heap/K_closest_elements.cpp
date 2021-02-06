//K closest elements https://www.youtube.com/watch?v=J8yLD-x7fBI&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=5
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<utility>
using namespace std;

int main(){
    priority_queue<pair<int, int>> max_heap;  //sorts on basis of pair.first()       pair< (abs(num[i] - X)), num[i] >
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    int x,  k;
    cin>>x>>k;
    for(int i=0;i<n;i++){
        max_heap.push({abs(a[i]-x), a[i]});
        if(max_heap.size()>=k+1){                       //removing after adding as the second value might be lesser than previous one
            max_heap.pop();
        }
    }
    while(max_heap.empty()==false){
        cout<<max_heap.top().second<<" ";
        max_heap.pop();
    }

}