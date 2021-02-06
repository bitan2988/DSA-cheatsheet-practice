//sum of numbers between k1 and k2 smallest element
//https://www.youtube.com/watch?v=_k_c9nqzKN0&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=9
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> max_heap;
    vector<int> num;
    int k1 = 3, k2 = 6;
    int sum = 0;
    for(int i=0;i<10;i++){
        num.push_back(i);
    }
    for(auto it=num.begin();it!=num.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int i=0;i<k2;i++){
        max_heap.push(num[i]);
        if(max_heap.size()>(k2-1)){       //excluding the k2 th smallest element as we  need to find sum of elements left to it
            max_heap.pop();
        }
    }
    cout<<max_heap.top()<<endl;
    while(max_heap.size()>k1){         //exclusing k1 th smallest element as we need sum of elements on right of it
        sum += max_heap.top();
        max_heap.pop();
    }
    cout<<max_heap.top()<<endl;
    cout<<sum;
}