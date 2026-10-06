class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open=0
        close=0
        for d in s:
            if d=='(':
                open+=1
            elif open>0:
                open-=1
            else:
                close+=1
        return open+close