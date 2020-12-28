#https://www.youtube.com/watch?v=We3YDTzNXEk

s = input("Enter the string: ")
dp = [[0 for x in range(len(s))] for y in range(len(s))]
for i in range(len(s)):
    dp[i][i] = 1
    if(i<len(s)-1):
        if(s[i]==s[i+1]):
            dp[i][i+1] = 1
#print(dp)
n = len(s)
k = 3        #k = length of the substring
maxLength = 0;
while (k<=n):
        # Fix the starting index
    i = 0
    while i<(n-k+1):
             
            # Get the ending index of 
            # substring from starting 
            # index i and length k
        j = i+k-1
     
            # checking for sub-string from
            # ith index to jth index if
            # st[i + 1] to st[(j-1)] is a 
            # palindrome
        if (dp[i+1][j-1] and s[i]==s[j]) :
            dp[i][j] = 1
            if (k>maxLength) :
                start = i
                maxLength = k
        i = i + 1
    k = k + 1
#print(dp)
print(maxLength)