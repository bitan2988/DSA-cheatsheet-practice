/* LIKE IN INSERTION_SORT FOR THE LEFT SIDE OF THE ARRAY WHILE MOVING A VALUE TO ITS CORRECT POSITION WE USED TO CHECK WITH EVERY ELEMENT WHICH IS CURREENTLY 1 INDEX AWAY,  
FOR SHELL-SORT/ GAP ALGO/ H-SORTING WE SIMPLY COMPARE THE ELEMENT WHICH IS TO BE MOVED AT ITS CORRECT POSITION BY AN ELEMENT WHICH IS h INDEX AWAY FROM IT
THUS MAKING THE ARRAY H-SORTED */

//The gap/h generally starts with the length of the array and then reduced by half for evey pass e.g- 19->9->4->2->1

//**REMEMBER- A g-sorted aaray remains g-sorted even after being h-sorted

#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order keep adding one more element until the entire array is gap sorted
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct location for a[i] is found
			int j;			
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			
			// put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Array before sorting: \n";
	printArray(arr, n);

	shellSort(arr, n);

	cout << "\nArray after sorting: \n";
	printArray(arr, n);

	return 0;
}
