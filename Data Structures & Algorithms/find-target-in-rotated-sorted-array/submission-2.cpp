class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;

        while(l<r && nums[r] < nums[l]) {
            int mid = (l+r+1)/2;
            if(nums[l] > nums[mid]) {
                r = mid-1;
            } else if(nums[r] < nums[mid]) {
                l = mid;
            }
        }
        if(r == nums.size() -1) {
            int it =  lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if(nums[it] == target) return it;
            return -1;
        }
        
        int it = lower_bound(nums.begin()+r+1, nums.end(), target) - nums.begin();
        if(nums[it] == target) return it;
        it = lower_bound(nums.begin(), nums.begin()+r, target) - nums.begin();
        if(nums[it] == target) return it;
        return -1;
    }
};
