""" https://leetcode.com/problems/find-the-duplicate-number/solution/
// We here use floyd's cycle detection (fig in the link)
// we make the sudo linked list by pointing the value of a[0]=a0 to a[a0] then value of a[a0]=a1 to value at a[a1] and so on 
// by this method the duplicate value should start a loop as we will get two values pointing to same index """

class Solution:
    def findDuplicate(self, nums):
        # Find the intersection point of the two runners.
        # move tortoise at speed of 1 and hare at speed of 2
        # if they point to a same node then there is a loop
        tortoise = hare = nums[0]

        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise == hare:
                break
        
        # Find the "entrance" to the cycle.
        # move totoise to a[0] and then move both of them at same speed
        # if they again meet at a same node then thats the starting of the cycle

        tortoise = nums[0]
        while tortoise != hare:
            tortoise = nums[tortoise]
            hare = nums[hare]
        
        return hare
