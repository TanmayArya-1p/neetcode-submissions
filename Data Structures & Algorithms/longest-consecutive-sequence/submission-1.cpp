class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        unordered_set<int> mp;
        
        int n = nums.size();

        for(auto &i : nums) {
            mp.insert(i);
        }
        int low  = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int mx=-1;
        int curr=1;
        for(int i=low+1;i<high+1;i++) {
            if(mp.find(i)!=mp.end()) {
                curr++;
            } else {
                mx = max(mx,curr);
                curr = 0;
            }
        }
        mx = max(mx,curr);
        return mx;
    }
};
