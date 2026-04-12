class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // tree no loops
        vector<bool> visited(n, false);
        
        vector<vector<int>> adj(n, vector<int>());
        for(auto s : edges) {
            adj[s[0]].push_back(s[1]);
            adj[s[1]].push_back(s[0]);
        }


        function<bool(int, int)> dfs = [&](int source,int prev) {
            visited[source] = true;
            for(auto& nei : adj[source]) {
                if(nei == prev) continue;
                if(visited[nei]) {
                    return false;
                }
                if(!dfs(nei, source)) return false;
            }
            return true;

        };


        if(!dfs(0, -1)) return false;
        for(auto i: visited) {
            if(!i) return false;
        }
        return true;

    }
};
