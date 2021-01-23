#https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/

def arithematic(a, low, high):
    diff = min(a[1]-a[0], a[2]-a[1])     #what if the second value is missing     -->the diff bw two values will increase if a value bw them is missing
    while(low<=high):
        mid = (high+low)//2
        if(a[mid+1]-a[mid]!=diff):      #the value at mid+1 is missing
            print(a[0]+((mid+1)*diff))
            break
        if(a[mid]-a[mid-1]!=diff):      #the value at mid is missing
            print(a[0]+(mid*diff))
            break
        else:
            if(mid==(a[0]+(mid-1)*diff)):    #the value at mid follows the AP till here, so the missing value must be at right
                low = mid+1
            else:                            #the value at mid is greater than expected so the missing value must be on its left
                high = mid-1
if __name__ == "__main__":
    a = [2, 4, 8, 10, 12, 14]
    arithematic(a, 0,len(a)-1)