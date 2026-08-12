class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit=0
        n=len(prices)
        buy=float('inf')
        for price in prices:
            if price-buy>=0:
                maxprofit=max(maxprofit,price-buy)
            else:
                buy=price
            
        return maxprofit