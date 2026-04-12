class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // for each bar assign the first bar before it that is less than or equal to it
        // for each bar assing the first bar after it that is less than or equal to it
        int n = heights.size();



        std::stack<pair<int,int>> q;
        q.emplace(heights[n-1],n-1);

        std::vector<int> leb(n);
        std::vector<int> lea(n);

        for (int i = n-2; i>=0 ; i--) {

            auto& curr = heights[i];
            while (q.size()>0 && q.top().first > curr) {
                leb[q.top().second] = i;
                q.pop();
            }    
            q.emplace(curr, i);
        }
        while (q.size()>0) {
            leb[q.top().second] = -1;
            q.pop();
        }   



        q = {};
        q.emplace(heights[0],0);
        for (int i = 1; i<n ; i++) {

            auto& curr = heights[i];
            while (q.size()>0 && q.top().first > curr) {
                lea[q.top().second] = i;
                q.pop();
            }    
            q.emplace(curr, i);
        }
        while (q.size()>0) {
            lea[q.top().second] = n;
            q.pop();
        }   

        int ans = -1;

        for (int i = 0; i < n; i++) {
            // process left area
            int lind = leb[i]+1;
            int larea = (i-lind)*(heights[i]);
            // process right area
            int rind = lea[i]-1;
            int rarea = (rind-i)*heights[i];
            ans = max(ans, larea+rarea+heights[i]);
        }
        return ans;
    }
};
