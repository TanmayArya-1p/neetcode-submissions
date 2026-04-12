class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        #define ll long long
        ll curr = 0;


        ll mx = 0;
        for(int i = 0; i < nums.size();i++) {
            curr+=nums[i];
            if(curr <= 0) {
                curr = 0;
            }
            mx = max(mx, curr);
        }
        if(mx == 0) mx= *max_element(nums.begin(), nums.end());
        return mx;
    }
};
