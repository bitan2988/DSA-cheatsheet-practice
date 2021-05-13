// A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input unsorted array.
// Some Sorting Algorithm is stable by nature like Insertion Sort, Merge Sort and Bubble Sort etc. on the other hand Selection Sort and Shell Sort is not stable.

// A simple way to determine is a sorting technique is stable or not is by looking if an elemment has to move longer-distances in a given time to reach 
// its sorted position in these cases they genreally tend to over-pass equal elements 

// Another way is to look if there is an < or <= sign in comparisons as if there is <= then it wont pass the equal element 


template <class RandomAccessIterator>  
  void stable_sort ( RandomAccessIterator first, RandomAccessIterator last );  
  

template <class RandomAccessIterator, class Compare>  
  void stable_sort ( RandomAccessIterator first, RandomAccessIterator last,  Compare comp ); 




// C++ program for modifying Selection Sort so that it becomes stable.
#include <iostream>
using namespace std;

void stableSelectionSort(int a[], int n)
{
	// Iterate through array elements
	for (int i = 0; i < n - 1; i++)
	{

		// Loop invariant : Elements till a[i - 1] are already sorted.

		// Find minimum element from arr[i] to arr[n - 1].
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;

		// Move minimum element at current i.
		int key = a[min];
		while (min > i)
		{
			a[min] = a[min - 1];
			min--;
		}
		a[i] = key;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}


int main()
{
	int a[] = { 4, 5, 3, 2, 4, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	stableSelectionSort(a, n);
	printArray(a, n);
	return 0;
}
