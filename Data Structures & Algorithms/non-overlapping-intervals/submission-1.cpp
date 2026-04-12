class Solution {
public:

    std::optional<vector<int>> intersect(vector<int>& i1, vector<int>& i2) {
        if(i2[0] < i1[0]) {
            if(i1[0] >= i2[1]) {
                return std::nullopt;
            }
            return {{i2[0] , max(i1[1],i2[1])}};
        } else {
            if(i2[0] >= i1[1]) {
                return std::nullopt;
            }
            return {{i1[0] , max(i2[1],i1[1])}};         
        }
    }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
            return a[0] < b[0];
        });   

       vector<int> curr = {intervals[0][0] , intervals[0][1]};

        int ct = -1;
       for(int i =0; i< intervals.size(); i++) {
            auto in = intersect(curr, intervals[i]);
            if(in.has_value()) {
                ct++;
                if(curr[1] > intervals[i][1]) {
                    curr = intervals[i];
                }
            } else {
                curr = intervals[i];
            }
       } 
       return ct;
    }
};
