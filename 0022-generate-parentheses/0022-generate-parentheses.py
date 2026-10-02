class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans=[]
        def par(str,open,close,n,ans):
            if len(str)==2*n :
                ans.append(str)
                return
            if open<n:
                par(str+"(",open+1,close,n,ans)
            if close<open:
                par(str+")",open,close+1,n,ans)
        
        par("",0,0,n,ans)
        return ans