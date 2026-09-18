class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        s=set(nums)
        longest=0
        for x in s:
            if x-1 not in s:
                length=1
                curr=x
                while curr+1 in s:
                    curr+=1
                    length+=1
                longest=max(longest,length)
        return longest