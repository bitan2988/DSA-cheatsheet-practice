// Three way partioning is great for cases where we know there are multiple duplicate keys   (Dutch National Flag)(Dijkstra's 3-way-partioning)
// We have four pointers here and all the elements between the second and the third eleemnt are equal 

//       lo--- <V ---ptr1--- ==v ---ptr2--- >V ---high

/* Let v be the partioning item a[lo]
   Scan i from left to right
   		a[i]<v :
   			exchange a[ptr1] with a[i]
   			ptr1++
   			i++
   		a[i]>v :
   			exchange a[ptr2] with a[i]
   			high--
   		a[i]==v :
   			i++          */

void sort(int a, int lo, int hi)
{	
	int lt = lo, gt = hi;    //lt = ptr1   gt = ptr2
	int a = a[lo];
	int i = lo;

	while(i<=gt){

		if(a[i] < v){
			swap(a[lt], a[i]);
			lt++;
			i++;
		}

		else if(a[i] > v){

			swap(a[i], a[gt]);
			gt++;
		}

		else
			i++;
	}

	sort(a, lo, lt-1);
	sort(a, gt+1, hi);
}




