class Solution {
public:
    int missingNumber(vector<int>& nums) {
        #define ll long long

        int n = nums.size();
        ll s = 0;
        for(auto &i: nums) s+=i;
        s-=n*(n+1)/2;
        return -s;
    }
};
