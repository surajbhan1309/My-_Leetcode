class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        prefix=1
        suffix=1
        ans=float('-inf')
        for i in range(len(nums)):
            if prefix==0:
                prefix=1
            if suffix==0:
                suffix=1
            prefix*=nums[i]
            suffix*=nums[len(nums)-1-i]
            ans=max({ans,prefix,suffix})
        return ans