# https://www.youtube.com/watch?v=7FE5Q_Bqzw8&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=91
# We have to look for the longest sub-array with atmax k zeroes
# We main the sub-array by keeping the track of a sliding window
# if a[i]-to-a[j] has zeroes < k, then increase the size of window by incrementing j
# if a[i]-to-a[j] has zeroes >= k, then move the window forward by by incrementing j as well as i

def lco(arr, k):
    nz = 0 #no. of zeroes in the window
    ans = 0
    i = 0

    # iterrating over elements
    for j in range(len(arr)):
        # if the curr_ele is zero then increment zero_count
        if(arr[j]=='0'):
            nz +=1
        
        # while the number of zeroes is greater than k reduce the window size from left_hand_side
        while(nz > k):
            # if we encounter a zero than than will be remove as we are reducing the size of the window
            if(arr[i]=='0'):
                nz -=1
            i +=1

        ans = max(ans, j-i+i)   # max(previous_ans, current_window_size)
    return ans

if __name__ == "__main__":
    arr = ""
    k = int(input())

    a = list(map(int, input().split()))

    print(lco(arr, k))




    
        




