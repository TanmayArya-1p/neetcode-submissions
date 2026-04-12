class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxjump = 0;

        for(int i =0 ;i < nums.size(); i++) {
            if(i > mxjump) return false;
            mxjump = max(mxjump, i+nums[i]);
        }
        return true;
    }
};
