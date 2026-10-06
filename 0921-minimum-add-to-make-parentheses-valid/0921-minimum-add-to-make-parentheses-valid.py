class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        openandclose=0
        rem=0
        for d in s:
            if d=='(':
                openandclose+=1
            elif openandclose>0:
                openandclose-=1
            else:
                rem+=1
        return openandclose+rem