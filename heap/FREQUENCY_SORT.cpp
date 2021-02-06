//FREQUENCY SORT
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, int> umap;       //umap< frequency of num[i], num[i]>       to form the count array
    priority_queue<pair<int, int> > max_heap;      //pair< frequency, num[i] 
    int num[] = {4,4,3,1,1,1,4,4,5,5,1,1,6,6,6};
    int n = sizeof(num)/sizeof(num[0]);

    for(int i=0;i<n;i++){
        if(umap.find(num[i])==umap.end()){
            umap[num[i]] = 0;     //IF DOESNT EXIST IN THE HASH
        }
        umap[num[i]] += 1;    //INCREMENTING COUNT VALUE BY ONE IF NUMBER ALREADY EXIST
    }

    for (auto it : umap){
        max_heap.push({it.second, it.first});      //getting sorted in the heap on the basis of frequency
    }
    while(max_heap.empty()==false){
        cout<<max_heap.top().second<<" appears "<<max_heap.top().first<<" times"<<endl;
        max_heap.pop();
    }       
}