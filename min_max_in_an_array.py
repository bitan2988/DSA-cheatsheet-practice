a = [1,4,2,3,5,6,2,4,2,2,8,9]
if ((len(a)%2)==0):
    if (a[1]>a[0]):
        maxi = a[1]
        mini = a[0]
    else:
        maxi = a[0]
        mini = a[1]
    i = 2
else:
    maxi = mini = a[0]
    i = 1

#compare two elements at a time to bring spacecomplexity to O(n/2)
while (i<(len(a)-1)):
    #print("1")
    if a[i]>a[i+1]:
        if a[i]>maxi:
            maxi = a[i]
        if a[i+1]<mini:
            mini = a[i+1]
    else:
        if a[i+1]>maxi:
            maxi = a[i+1]
        if a[i]<mini:
            mini = a[i]
    i +=2
print(mini, maxi)