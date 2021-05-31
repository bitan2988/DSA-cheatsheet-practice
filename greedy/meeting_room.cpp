// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<pair<int, int>, int> m1, pair<pair<int, int>, int> m2)
{
    return m1.first.second < m2.first.second;
}

int meeting(vector<pair<pair<int, int>, int>> meet, int n){

    sort(meet.begin(), meet.end(), comparator);   // sorting in ascending order of end_time

    int res = 1;
    int final_time = meet[0].first.second;

    for(int i=0; i<n; i++){
        cout<<meet[i].second<<" "<<meet[i].first.first<<" "<<meet[i].first.second<<"\n";
    }

    for(int i=1; i<n; i++){

        if(meet[i].first.first >= final_time){

            final_time = meet[i].first.second;
            res++;
        }
    }

    return res;
} 

int main(){

    vector<pair<pair<int, int>, int>> meet; // <<start_time, end_time>, meeting_number> 

    int start_time[5] = {1, 1, 5, 7, 9};
    int end_time[5] = {3, 4, 9, 8, 11};

    int l = sizeof(start_time)/sizeof(start_time[0]); 

    for(int i=0; i < l; i++){

        meet.push_back({{start_time[i], end_time[i]}, i+1});
    }

    int max_meeting = meeting(meet, l);

    std::cout<<"\nMax meeting that can take place is "<<max_meeting<<"\n";
}