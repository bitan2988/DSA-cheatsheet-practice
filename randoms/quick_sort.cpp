/*                                                                           QUICK-SORT    https://www.geeksforgeeks.org/quick-sort/

First and foremost we shuffle the array

We choose a partitioning element (lo) first, 
the partitioning element should be such that every element on its right should be greater than it and 
every element to its left should be less than it

	after this pass we can guarantee that a[lo] is at its correct position

	We then repeat the same for the left half and the right half



i = 1, j = arr.size() - 1;
lo = a[0]

Repeat until i and j cross
	scan i from left-to-right so long as (a[i] < a[lo])
		if not found i++
	scan j from right-to-left so long as (a[j] > a[lo])
		if not  j--
	Exchange a[i] with a[j]
		swap(a[i], a[j])  

When pointers cross 
	Exchange a[lo] with a[j]                     */


int partition(int a[], int low, int high ){

	int i = low;
	int j = high;

	int lo = low;


	int arr_size = j-i;

	if((j - i)==1){
		return;   //only one element present
	}

	while(i > j){

		while(a[i] <= a[lo] and i > j){
			i++;
		}

		while(a[j] > a[lo] and i > j){
			j--;
		}

		if(i < j)
			swap(a[i], a[j]);
		
	}

	swap(a[lo], a[j]);

	return j; //partioning position
}

void quick_sort(int a[], int low, int high){

	if(low < high)
		int j = partition(a, low, high);    // partition index

	quick_sort(low, j);  // for the left array

	quick_sort(j+1, high);   // for the right array
}





---------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}


