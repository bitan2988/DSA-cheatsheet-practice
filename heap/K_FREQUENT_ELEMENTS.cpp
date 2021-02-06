//K frequent number     https://www.youtube.com/watch?v=7VoJn544QrM&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=6
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>
#include<utility>
using namespace std;

int main(){
    unordered_map<int, int> umap;       //umap< frequency of num[i], num[i]>       to form the count array
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;       //pair< frequency, num[i] 
    int num[] = {4,4,3,1,1,1,4,4,5,5,1,1,6,6,6};
    int n = sizeof(num)/sizeof(num[0]);
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        if(umap.find(num[i])==umap.end()){
            umap[num[i]] = 0;
        }
        umap[num[i]] += 1;
    }
    /*for(auto it : umap)                             // for(auto it=umap.begin();it!=umap.end();it++)
        cout<<it.first<<" "<<it.second<<endl;*/
    for (auto it : umap){
        min_heap.push({it.second, it.first});      //getting sorted in the heap on the basis of frequency
        if(min_heap.size()>=k+1){
            min_heap.pop();
        }
    }
    while(min_heap.empty()==false){
        cout<<min_heap.top().second<<" appears "<<min_heap.top().first<<" times"<<endl;
        min_heap.pop();
    }       
}