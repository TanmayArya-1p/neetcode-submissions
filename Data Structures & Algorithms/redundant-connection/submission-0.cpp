class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> visited;
        map<int, vector<int>> adj;
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ind = 0;
        map<pair<int,int>,int> edgeindmp;
        for(auto &edge : edges) {
            edgeindmp[{min(edge[0],edge[1]), max(edge[0],edge[1])}] = ind;
            ind++;
        }


        function<vector<pair<int,int>>(int,int)> dfs = [&](int s, int prev) -> vector<pair<int,int>> {
            visited.insert(s);
            for(auto &nei : adj[s]) {
                if(prev == nei) continue;
                if(visited.find(nei) == visited.end()) {
                    auto otpt = dfs(nei, s);
                    if(!otpt.empty()) {
                        if(s<nei) {
                            otpt.push_back({s,nei});
                        } else {
                            otpt.push_back({nei,s});
                        }
                        return otpt;
                    }
                } else {
                    if(s<nei) {
                        return vector<pair<int,int>>{{s, nei}};
                    } else {
                        return vector<pair<int,int>>{{nei, s}};
                    }
                }
            }
            return vector<pair<int,int>>();
        };
        auto ans = dfs(edges[0][0],-1);
        
        auto otpt = *max_element(ans.begin(), ans.end(), [&](const auto& a, const auto& b) {
            return edgeindmp[a] < edgeindmp[b];
        });

        return {otpt.first, otpt.second};
    }
};
