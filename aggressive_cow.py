def isFeasible(mid, arr, n, k):
	pos = arr[0]
	elements = 1
	for i in range(1, n):
		if (arr[i] - pos >= mid):
			pos = arr[i]
			elements += 1
			if (elements == k):
				return True
	return False
def largestMinDist(arr, n, k):
	arr.sort()
	res = -1
	left = arr[0]
	right = arr[n - 1]
	while (left < right):
		mid = (left + right) / 2
		if (isFeasible(mid, arr, n, k)):
			res = max(res, mid)
			left = mid + 1
		else:
			right = mid
	return res

if __name__ == "__main__":
	arr = [1, 2, 8, 4, 9]
	n = len(arr)
	k = 3
	print(largestMinDist(arr, n, k))

#we use binary search here to find the max gap
#we start fromm the maximum gap possible and then comes down
#if we come accross a gap that accomomdates all the elements then we look on its right to find a gap with higher value that acoomodates all
#else we look on its left for a gap with lower value
#almost like searching for a pivot in a rotated sorted array