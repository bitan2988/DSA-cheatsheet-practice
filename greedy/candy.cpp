
//https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        
        int i = 0;
        int j = N-1;
        
        int min = 0, max = 0;
        
        while(i<=j){
            min += candies[i];
            i++;
            j -= K;
            
        }
        
         i=0;
         j=N-1;
        
        while(j>=i){
            max += candies[j];
            j--;
            i +=K;
        }
        
        vector<int> vec = {min, max};
        
        return vec;
    }
};