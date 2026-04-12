#include <bits/stdc++.h>
#include <set>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> pq;
        for (int i =0; i < min(nums.size(),(size_t)k); i++) {
            pq.insert(nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i< nums.size()-k+1; i++) {
            ans.push_back(*(--pq.end()));
            pq.erase(pq.find(nums[i]));
            pq.insert(nums[i+k]);
        }
        return ans;
    }
};


// int main () {
//     Solution* s = new Solution();

//     vector<int> a = {1,2,1,0,4,2,6};
//     for (auto&i :  s->maxSlidingWindow(a, 3)) {
//         cout << i << " ";
//     }
//     cout << endl;
// }
