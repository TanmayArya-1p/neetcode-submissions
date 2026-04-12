class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i =0;
        int j = nums.size()-1;
        while(i<j) {
            cout << i << " " << j << endl;
            int mid = (i+j+1)/2;
            if(target<nums[mid]) {
                j = mid-1;
            } else {
                i = mid;
            }
        }
        if(nums[j] == target) return i;
        return -1;
    }
};
