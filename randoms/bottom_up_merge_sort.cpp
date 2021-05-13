/*  The basic idea is to initially consider each element as a sorted array of size 1,
	then we merge two such arrays and make a sorted array of size 2 , then of size 4
	we repeat till we get the whole array sorted or till the length reaches the length of the initial array 

	No Recursion is needed for this method    */

int n = arr.size();

for(int sz=0; sz < n; i = 2*sz){   //sz is the size of the array that needs to be merged

	for(int low = 0; low < n-sz; low += 2*sz)
		merge(arr, low, low+sz-1, min(low+sz+sz-1, n-1))
}


void merge(int a[], int low, int mid, int high){

	int n1 = m id- low + 1;
    int n2 = high - mid;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid+ 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}