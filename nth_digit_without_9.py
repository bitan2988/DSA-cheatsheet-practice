#very important
# 1. Decrease the number N by 1.
# 2. Convert the number N to base 9

# n'th number without the number 9
class Solution:
    def findNth(self,N):
        def ans(n):
            if(n<9):  #if less than 9 then return as it is
        	    return n
            return (n%9)+(10*(ans(n//9)))   #converting to base 9
        def gsn(n):
            return ans(n-1)
        return int(gsn(n+1))

t=int(input())
for i in range(0,t):
    n=int(input())
    obj=Solution()
    s=obj.findNth(n)
    print(s)
#https://www.geeksforgeeks.org/n-th-number-with-digits-in-0-1-2-3-4-5/

#    while(num!=0)
    #{
    #    rem = num%k;
    #    res = (rem*i)+res;
    #    num = num/k;
    #    i = i*10;
    #}
# converting base 10 to base k    