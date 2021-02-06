//https://www.youtube.com/watch?v=_k_c9nqzKN0&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=9
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > min_heap;
    int rope[] = {1,2,3,4,5};
    int n = sizeof(rope)/sizeof(rope[0]);
    int top, second_top, cost = 0;
    int current_cost;
    for(int i=0; i<n; i++){
        min_heap.push(rope[i]);
    }
    /**
     * @brief Minimal cost is obtained when the two shortest ropes are connected in the current arsenal is
     * connected to make a longer rope
     */
    while(min_heap.size()>=2){     
        top = min_heap.top();
        min_heap.pop();
        second_top = min_heap.top();
        min_heap.pop();
        current_cost = (top + second_top);
        cost += current_cost;
        min_heap.push(current_cost);
    }
    cout<<cost;
}