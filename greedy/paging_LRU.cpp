 /* In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needed to be replaced when new page comes in.
    Whenever a new page is referred and not present in memory, page fault occurs and Operating System replaces one of the existing pages with newly needed page. 
    Different page replacement algorithms suggest different ways to decide which page to replace. 
    The target for all algorithms is to reduce number of page faults.

    In Least Recently Used (LRU) algorithm is a Greedy algorithm where the page to be replaced is least recently used. 
    The idea is based on locality of reference, the least recently used page is not likely

    Let capacity be the number of pages thatmemory can hold.  
    Let set be the current set of pages in memory.

    1- Start traversing the pages.
        i) If set holds less pages than capacity.

            a) Insert page into the set one by one until 
               the size  of set reaches capacity or all page requests are processed.
            b) Simultaneously maintain the recent occurred
               index of each page in a map called indexes.
            c) Increment page fault

        ii) Else 
            If current page is present in set, do nothing.

        Else 
            a) Find the page in the set that was least recently used. We find it using index array.
               We basically need to replace the page with minimum index.
            b) Replace the found page with current page.
            c) Increment page faults.
            d) Update index of current page.

    2. Return page faults.    */


#include<bits/stdc++.h>
using namespace std;

// Function to find page faults using indexes
int pageFaults(int pages[], int n, int capacity)
{
	// To represent set of current pages. We use an unordered_set so that we quickly check if a page is present in set or not  <page_value>
	unordered_set<int> s;

	// To store least recently used indexes of pages.   <page_value, index>
	unordered_map<int, int> indexes;

	// Start from initial page
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		// Check if the set can hold more pages
		if (s.size() < capacity)
		{
			// Insert it into set if not present already which represents page fault
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);

				// increment page fault
				page_faults++;
			}

			// Store the recently used index of each page
			indexes[pages[i]] = i;  
			cout<<"Inserted "<<pages[i]<<" "<<indexes[pages[i]]<<"\n";
		}

		// If the set is full then need to perform lru i.e. remove the least recently used page and insert the current page
		else
		{
			// Check if current page is not already present in the set
			if (s.find(pages[i]) == s.end())
			{
				// Find the least recently used pages that is present in the set aka the value in-front
				int lru = INT_MAX, val;
				for (auto it=s.begin(); it!=s.end(); it++)    // iterating over the set 
				{
					// selecting the value with the least page_value
					if (indexes[*it] < lru)   // if page_value is less than my lru
					{
						lru = indexes[*it];   // set lru = page_value
						val = *it;     // set value = index
						cout<<"from map "<< *it<<" "<<indexes[*it]<<"\n";
					}
				}

				// Remove the indexes page from the set
				s.erase(val);

				// insert the current page
				s.insert(pages[i]);

				// Increment page faults
				page_faults++;
			}

			// If present in the set then Update the current page index
			indexes[pages[i]] = i;   // Setting to the recent index at which the value is found
			cout<<"updated "<< pages[i]<<" "<<indexes[i]<<"\n";
		}
	}

	return page_faults;
}

// Driver code
int main()
{
	int pages[] = {7, 19, 18, 2, 19, 3, 19, 4, 33, 3, 19, 3, 33};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 4;
	cout << pageFaults(pages, n, capacity);
	return 0;
}

