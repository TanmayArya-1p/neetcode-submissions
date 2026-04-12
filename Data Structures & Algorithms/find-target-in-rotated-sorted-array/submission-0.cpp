#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;

        while(i<j) {
            int mid = (i+j)/2;
            if(nums[mid] < nums[j]) {
                j = mid;
            } else {
                i = mid+1;
            }
        }

        auto s1 = lower_bound(nums.begin() , nums.begin()+(i), target);
        if(s1 != nums.begin()+(i) && *s1 == target) {
            return s1 - nums.begin();
        }

        auto s2 = lower_bound(nums.begin()+i , nums.end(), target);
        if(s2 != nums.end() && *s2 == target) {
            return s2 - nums.begin();
        }

        return -1;
    }
};
