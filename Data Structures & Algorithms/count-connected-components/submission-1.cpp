class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n , false);

                vector<vector<int>> adj(n, vector<int>());
        for(auto s : edges) {
            adj[s[0]].push_back(s[1]);
            adj[s[1]].push_back(s[0]);
        }


        function<void(int,int)> dfs = [&](int source, int prev) {
            visited[source] = true;

            for(auto &i : adj[source]) {
                if(visited[i]) continue;
                dfs(i, source);
            }
        };
        
        int ct = 0;
        for(int i = 0;i < n;i++) {
            if(!visited[i]) {
                ct++;
                dfs(i, -1);
            }
        }
        return ct;

    }
};
