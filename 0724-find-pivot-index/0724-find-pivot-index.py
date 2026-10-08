class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        psum=0
        ssum=sum(nums)
        for i in range(0,len(nums)):
            ssum-=nums[i]
            if psum==ssum:
                return i
            psum+=nums[i]
        return -1