class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int i = 0;
        int j = n-1;


        while(i < j) {
            int mid = i + (j-i+1)/2;

            if(nums[mid] > nums[i]) {
                i = mid;
            } else {
                j = mid-1;
            }
        }
        

        return nums[(i+1)%n];
    }
};
