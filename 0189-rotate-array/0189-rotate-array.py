class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        n=len(nums)
        ans=[0]*n
        k%=n
        for i in range(n):
            ans[(i+k)%n]=nums[i]
        nums[:]=ans
        