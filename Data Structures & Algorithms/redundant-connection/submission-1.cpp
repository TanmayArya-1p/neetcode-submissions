class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, set<int>> adj;
        set<int> rem;
        queue<int> prune;
        for(auto &edge : edges) {
            rem.insert(edge[1]);
            rem.insert(edge[0]);

            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        for(auto &i : adj) {
            if(i.second.size() == 1) {
                prune.push(i.first);
            }
        }

        while(!prune.empty()) {
            int curr = prune.front();
            prune.pop();

            int nei = *adj[curr].begin();
            adj.erase(curr);
            rem.erase(curr);
            cout << "PRUNED " << curr << endl;
            adj[nei].erase(curr);
            if(adj[nei].size() == 1) {
                prune.push(nei);
            }
        }


        for(int i = edges.size()-1 ; i >=0 ;i--) {
            if(rem.find(edges[i][0]) != rem.end() && rem.find(edges[i][1]) != rem.end()) {
                return edges[i];
            }
        }
        return {};
    }
};
