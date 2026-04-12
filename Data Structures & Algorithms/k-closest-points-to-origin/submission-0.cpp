#define ll long long
ll radsquare(const pair<int,int>& a) {
    return a.first*a.first + a.second*a.second;
}


template<class T>
struct OriginDistance {
    constexpr bool operator() (const pair<int,int>& a, const pair<int,int>& b) const {
        T init = {};
        return init(radsquare(a),radsquare(b));
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, OriginDistance<std::less<ll>>> pq;
       for(auto& pt: points) {
            pair<int,int> curr = {pt[0],pt[1]};
            if(pq.size() < k) {
                pq.push(curr);
            } else {
                if(radsquare(curr) > radsquare(pq.top())) {
                    continue;
                } else {
                    pq.pop();
                    pq.push(curr);
                }
            }
       
       }
       vector<vector<int>> ans;
       ans.reserve(pq.size());
       while(!pq.empty()) {
        auto i = pq.top();
        pq.pop();
        ans.push_back({i.first, i.second});
       }



       return ans;
    }
};
