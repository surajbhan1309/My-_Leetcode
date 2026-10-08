class Solution:
    def countHillValley(self, nums: list[int]) -> int:
        n = len(nums)
        count = 0
        
        for i in range(1, n - 1):
            if nums[i] == nums[i - 1]:
                continue
                
            j = i - 1
            k = i + 1
            
            while j >= 0 and nums[j] == nums[i]:
                j -= 1
                
            while k < n and nums[k] == nums[i]:
                k += 1
            
            if j >= 0 and k < n:
                if (nums[i] < nums[j] and nums[i] < nums[k]) or (nums[i] > nums[j] and nums[i] > nums[k]):
                    count += 1
                    
        return count
