# https://www.youtube.com/watch?v=T-Oj2Ajj9vA&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=91
# Longest sub-string without duplicate character 
# We make use of hash table to store the previous occurance of a character and then 


# if we encounter the repeating character that means from that index a new substring has to be considered 
# so start marks the starting index of the sub_string whereas i marks the right_pointer for that sub_string
def ls(s):
    dic = [-1 for i in range(26)]   # only lower letters
    max_len = 0
    start = -1   

    for i in range(len(s)):
        # if char has appeared previously
        if dic[ord(s[i]) - ord('a')] > start:    
            start = dic[ord(s[i]) - ord('a')]    # updating start i.e moving the left_pointer of the window 
         
        dic[ord(s[i]) - ord('a')] = i    # updating the last occurance of the character

        max_len = max(max_len, i-start)

    return max_len


if __name__ == "__main__":
    s = input()
    print(ls(s))