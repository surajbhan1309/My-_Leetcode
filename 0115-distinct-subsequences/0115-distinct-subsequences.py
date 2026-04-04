class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        self.s = s
        self.t = t
        self.n = len(s)
        self.m = len(t)
        
        self.dp = [[-1] * (self.m + 1) for _ in range(self.n + 1)]
        
        return self.solve(0, 0)
        
    def solve(self, i, j):
        if j == self.m:
            return 1
        if i == self.n:
            return 0
        
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        
        if self.s[i] == self.t[j]:
            self.dp[i][j] = self.solve(i + 1, j + 1) + self.solve(i + 1, j)
        else:
            self.dp[i][j] = self.solve(i + 1, j)
        
        return self.dp[i][j]