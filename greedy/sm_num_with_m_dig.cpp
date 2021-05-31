//https://www.geeksforgeeks.org/find-smallest-number-with-given-number-of-digits-and-digit-sum/


string smallestNumber(int S, int D){
	int s = S;
  	int m = D;
        
    string resu = "";
    string n = "-1";
        
    if (s == 0)
    {
        //(m == 1)? cout << "Smallest number is " << 0 : cout << "Not possible";
            return n;
    }
     
    // Sum greater than the maximum possible sum.
    if (s > 9*m)
    {
        //cout << "Not possible";
        return n;
    }
     
    // Create an array to store digits of result
    int res[m];
     
        // deduct sum by one to account for cases later (There must be 1 left for the most significant digit)
        s -= 1;
     
    // Fill last m-1 digits (from right to left)
    for (int i=m-1; i>0; i--)
    {
        // If sum is still greater than 9, digit must be 9.
        if (s > 9)
        {
           res[i] = 9;
            s -= 9;
        }
            else
        {
            res[i] = s;
            s = 0;
        }
    }
     
        // Whatever is left should be the most significant digit.
    res[0] = s + 1;
    
	for(int i=0; i<m; i++){
            
        resu = resu + char(int('0') + res[i]);        
    }
            
    return resu;
        
    }