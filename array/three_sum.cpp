#include<iostream>
#include<algorithm>
using namespace std;

int main(){

   int arr[]={};
   int n = sizeof(arr)/sizeof(arr[0]);
   
   sort(arr, arr+n);

   for(int i=0; i<n; i++){
      int low = 0;
      int high = n-1;
	
	
      while((high - low) > 1){
         if(arr[low]+arr[high]+arr[i]==sum){
	     cout<<sum;
	     break;
	  }
	  else if(arr[low]+arr[high]+arr[i] > sum)
	     high--;
	  else
	     low++;
      }
   }
}


// Time complexity O(NlogN) + O(N*N) = O(N^2)
