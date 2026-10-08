class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n=len(s)
        left=0
        ans=0
        mp=defaultdict(int)
        for right in range(n):
            mp[s[right]]+=1
            while mp[s[right]]>1:
                mp[s[left]]-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans