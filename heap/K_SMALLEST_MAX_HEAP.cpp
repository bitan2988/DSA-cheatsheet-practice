//FIND THE K'th SMALLEST ELEMENT
#include<iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> max_heap;
    int a[10] = {5, 6, 3, 10, 7, 9, 1, 4, 8, 2};
    int k = 4;
    for(int i=0;i<10;i++){
        if(max_heap.size()==k){
            max_heap.pop();
        }
        max_heap.push(a[i]);
    }
    cout<<max_heap.top();
}
// as we are asked to find the k'th smallest element that means it must be present in the k'th position from below in the max_heap 
// thus we simply remove the largest element or the element above index k as they must not from the k'th smallest element