class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pref = [prices[0]]
        n = len(prices)
        for i in range(1,n):
            pref.append(min(pref[-1],prices[i]))
        
        mx = -1
        for i in range(1,n):
            mx=max(mx,prices[i]-pref[i-1])
        return max(mx,0)

        