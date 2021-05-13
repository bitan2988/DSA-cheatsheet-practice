// C++ program for activity selection problem.
// The following implementation assumes that the activities are already sorted according to their finish time
#include <bits/stdc++.h>
using namespace std;

// Prints a maximum set of activities that can be done by a single person, one at a time.
// n --> Total number of activities
// s[] --> An array that contains start time of all activities
// f[] --> An array that contains finish time of all activities
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	cout <<"Following activities are selected "<< endl;

	// The first activity always gets selected
	i = 0;
	cout <<" "<< i;

	// Consider rest of the activities
	for (j = 1; j < n; j++)
	{
	// If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
	if (s[j] >= f[i])
	{
		cout <<" " << j;
		i = j;
	}
	}
}

// driver program to test above function
int main()
{
	int s[] = {1, 3, 0, 5, 8, 5};
	int f[] = {2, 4, 6, 7, 9, 9};
	int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(s, f, n);
	return 0;
}
//this code contributed by shivanisinghss2110





//FOR IDE PROBLEM
//---------------

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        maxMeetings(start, end, n);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends

// struct comp{
//   bool operator()(pair<int,int> &x, pair<int,int> &y){
//       return (x.first>y.first)?(true:(x.second<y.second)?true:false);
//   }  
// };
void maxMeetings(int start[], int end[], int n){
    //As there can we have to have job "sorted" with minimum finish times
    //and also there can be two different job with same finish time hence using multimap
    //note that since when two jobs have same finish time, then we have to pick the one which came first
    //Therefore the pair with <end_time,index>, start time
    multimap<pair<int, int>, int> meetings;
    int busy_until = 0;
    vector<int> result;
    for (int i = 0; i < n; i++)
        meetings.insert({{end[i], i + 1}, start[i]});
    for (auto it : meetings)
        if (it.second > busy_until)
            result.push_back(it.first.second), busy_until = it.first.first;
    for (auto it : result)
        cout << it << " ";
}


/*Greedy-Iterative-Activity-Selector(A, s, f): 

    Sort A by finish times stored in 
    S = {A[1]} 
    k = 1
    
    n = A.length
    
    for i = 2 to n:
        if s[i] ≥ f[k]: 
            S = S U {A[i]}
            k = i
    
    return S

Explanation
Line 1: This algorithm is called Greedy-Iterative-Activity-Selector, because it is first of all a greedy algorithm, and then it is iterative. There's also a recursive version of this greedy algorithm.

A is an array containing the activities.
s is an array containing the start times of the activities in A.
f is an array containing the finish times of the activities in A.
Note that these arrays are indexed starting from 1 up to the length of the corresponding array.

Line 3: Sorts in increasing order of finish times the array of activities A by using the finish times stored in the array f. This operation can be done in O(N*logN) time, using for example merge sort, heap sort, or quick sort algorithms.

Line 4: Creates a set S to store the selected activities, and initialises it with the activity A[1] that has the earliest finish time.

Line 5: Creates a variable k that keeps track of the index of the last selected activity.

Line 9: Starts iterating from the second element of that array A up to its last element.

Lines 10,11: If the start time s[i] of the ith activity (A[i]) is greater or equal to the finish time {f[k] of the last selected activity (A[k]), then A[i] is compatible to the selected activities in the set S, and thus it can be added to S.

Line 12: The index of the last selected activity is updated to the just added activity */