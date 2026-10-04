class Solution:
    def minRotations(self, s: str) -> int:
        ans=min(10-int(s[0]),int(s[0]))
        for i in range(1,len(s)):
            ans+=min(10-abs(int(s[i])-int(s[i-1])),abs(int(s[i])-int(s[i-1])))
            print(ans)
        return ans