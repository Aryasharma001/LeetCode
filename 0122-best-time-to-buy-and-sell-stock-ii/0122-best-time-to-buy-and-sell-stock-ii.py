class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sum = 0
        for i in range(1, len(prices)):
                sum += (prices[i] - prices[i-1]) if prices[i] >= prices[i-1] else 0
        return sum