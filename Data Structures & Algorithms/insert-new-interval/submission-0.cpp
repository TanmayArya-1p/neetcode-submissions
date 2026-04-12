class Solution {
public:


    std::optional<vector<int>> intersect(vector<int>& i1, vector<int>& i2) {
        if(i2[0] < i1[0]) {
            if(i1[0] > i2[1]) {
                return std::nullopt;
            }
            return {{i2[0] , max(i1[1],i2[1])}};
        } else {
            if(i2[0] > i1[1]) {
                return std::nullopt;
            }
            return {{i1[0] , max(i2[1],i1[1])}};         
        }
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> ans;
        bool done = false;
        for(int i=0;i<intervals.size();i++) {
            auto in = intersect(intervals[i], ni);
            if(in.has_value()) {
                done = true;
                intervals[i] = in.value();
                cout << "REPLACED " << in.value()[0] << " " << in.value()[1] << endl;
            }
        }
        if(done) {
            vector<int> curr = {intervals[0][0], intervals[0][1]};
            
            for(int i = 0 ; i< intervals.size();i++) {
                auto in = intersect(curr, intervals[i]);
                if(in.has_value()) {
                    curr[0] = in.value()[0];
                    curr[1] = in.value()[1];
                } else {
                    ans.push_back(curr);
                    curr = intervals[i];
                }
            }
            ans.push_back(curr);
        } else {
            intervals.push_back(ni);
            sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
                return a[0] < b[0];
            });
            return intervals;
        }

        intervals = ans;
        return intervals;

    }
};
