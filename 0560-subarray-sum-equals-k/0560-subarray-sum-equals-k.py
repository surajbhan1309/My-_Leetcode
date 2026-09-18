class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix=defaultdict(int)
        count=0
        sum=0
        prefix[0]=1

        for num in nums:
            sum+=num
            count+=prefix[sum-k]
            prefix[sum]+=1
        
        return count