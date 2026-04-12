class Solution {
public:

    #define INF 10000007
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefmx(n,0);
        prefmx[0] = nums[0];
        for(int i =1 ;i<n; i++) {
            prefmx[i] = max(prefmx[i-1], i+nums[i]);
        }

        int mx = 0;
        int ct = 0;
        while(mx < n-1) {
            ct++;   
            mx = prefmx[mx];
        }
        return ct;
    }
};
