class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n=len(nums)
        premax=[0]*n
        suffmax=[0]*n
        ans=[0]*n
        premax[0]=nums[0]
        for i in range(1,n):
            premax[i]=max(premax[i-1],nums[i])
        suffmax[n-1]=nums[n-1]
        for i in range(n-2,-1,-1):
            suffmax[i]=min(suffmax[i+1],nums[i])
        ans[n-1]=premax[n-1]
        for i in range(n-2,-1,-1):
            if(premax[i]>suffmax[i+1]):
                ans[i]=ans[i+1]
            else:
                ans[i]=premax[i]
        return ans