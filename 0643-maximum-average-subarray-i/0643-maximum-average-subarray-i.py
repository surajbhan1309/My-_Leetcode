class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        left=0
        n=len(nums)
        ans=float("-inf")
        sum=0
        for right in range(n):
            sum+=nums[right]
            while right-left+1>k:
                sum-=nums[left]
                left+=1
            if right-left+1==k:
                ans=max(ans,sum/k)
        return ans
            