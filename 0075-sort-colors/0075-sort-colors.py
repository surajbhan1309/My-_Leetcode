class Solution:
    def sortColors(self, nums: List[int]) -> None:
        right=len(nums)-1
        left=0
        mid=0
        while mid<=right:
            if nums[mid]==0:
                nums[left],nums[mid]=nums[mid],nums[left]
                left+=1
                mid+=1
            elif nums[mid]==1:
                mid+=1
            else:
                nums[right],nums[mid]=nums[mid],nums[right]
                right-=1
        

        