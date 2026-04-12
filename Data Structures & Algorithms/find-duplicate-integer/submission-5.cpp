class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;

        bool nc = false;
        for(auto& i : nums) {
            if(i == n) {
                if(!nc) nc = true;
                else return n;
            }

        }

        int fast = 0;
        int slow = 0;

        int prev;

        do {
            cout << slow << " " << fast << endl;
            int p = nums[fast];
            fast = nums[p];
            prev = slow;
            slow = nums[slow];
        } while(fast != slow);

        fast = 0;
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }        

        return slow;

    }
};
