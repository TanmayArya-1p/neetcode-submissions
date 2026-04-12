class Solution {
public:

    #define ll long long
    const ll INF = 1e10;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<ll> dp(n+1,INF);
        dp[0] = 0;
        dp[1] = 0;
        for(int i =2; i <= n;i++) {
            dp[i] = min(dp[i-1] + 1LL*cost[i-1] , dp[i-2] + 1LL*cost[i-2]);
        }
        return dp[n];
    }
};
