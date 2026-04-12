class Solution {
public:

    #define INF 10000007
    int jump(vector<int>& nums) {
        int n = nums.size();


        vector<int> dp(n, INF);
        dp[0] = 0;

        for(int i =0 ;i < n; i++) {
            for(int j = i; j<=min(i+nums[i], n-1); j++) {
                dp[j] = min(dp[i]+1, dp[j]);
            }
        }
        return dp[n-1];
    }
};
