#include<bits/stdc++.h>
using namespace std;
    
    
    //Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {

    sort(arr, arr + n);
    sort(dep, dep + n);

    // plat_needed indicates number of platforms needed at a time
    int plat_needed = 1, result = 1;

    // i to iterrate through arrival array and j for the departure array
    int i = 1, j = 0;

    // Similar to merge in merge sort to process all events in sorted order
    while (i < n && j < n) {

        // If next event in sorted order is arrival, increment count of platforms needed
        // If a train arrives before a train leaves the platform in that case we will need another platform
        if (arr[i] <= dep[j]) {   
            plat_needed++;
            i++;
        }

        // Else decrement count of platforms needed
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }

        // Update result if needed
        if (plat_needed > result)
            result = plat_needed;
    }

    return result;
    	
    }



/*      This approach assumes that trains are arriving and departing on the same date.

        Algorithm:
            Sort the arrival and departure time of trains.
            Create two pointers i=0, and j=0 and a variable to store ans and current count plat
            Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
            if the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
            Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat++ and increment j
            Update the ans, i.e ans = max(ans, plat).                                                                                                   */