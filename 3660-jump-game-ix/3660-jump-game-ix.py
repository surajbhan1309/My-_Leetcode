class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)

        prefixmax = [0] * n
        suffixmin = [0] * n
        ans = [0] * n

        prefixmax[0] = nums[0]
        for i in range(1, n):
            prefixmax[i] = max(prefixmax[i - 1], nums[i])

        suffixmin[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            suffixmin[i] = min(suffixmin[i + 1], nums[i])

        ans[n - 1] = prefixmax[n - 1]

        for i in range(n - 2, -1, -1):
            if prefixmax[i] > suffixmin[i + 1]:
                ans[i] = ans[i + 1]
            else:
                ans[i] = prefixmax[i]

        return ans