class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int,int>> q;
        std::vector<int> ans(temperatures.size(),0);

        for (int i = 0 ; i < temperatures.size() ; i++) {
            while(!q.empty() && q.top().first < temperatures[i]) {
                ans[q.top().second] = i-q.top().second;
                q.pop();
            }

            q.push({temperatures[i],i});
        }
        return ans;
    }
};
