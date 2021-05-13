//  Our objective is to find the k th largest element

//we use the quick sort partition here to find the k'th largest elment 
// since we know in the partition at  j all element at left of j are less than it 
// and all the elemnts to its rigght is greater than k thus we can make use of it to 
// decide whether our element will lie in the RHS or LHS

int lo=0, hi=arr.size()-1;

while(hi>lo){

	int j = partition(arr, lo, hi);
	if(j<k){
		lo = j+1;
	}
	else if(j>k){
		hi = j-1;
	}
	else
		return arr[k];
}

return arr[k];