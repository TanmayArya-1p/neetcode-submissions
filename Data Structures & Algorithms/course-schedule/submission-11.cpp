class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n, vector<int>());
        vector<bool> source(n, true);
        for(auto &i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            source[i[0]] = false;
        }

        vector<bool> visited(n, false);
        
        vector<int> toposort;
        toposort.reserve(n);
        
        std::function<void(int)> dfs = [&](int s) mutable {
            visited[s] = true;

            for(auto& i: adj[s]) {
                if(!visited[i]) dfs(i);
            }
            toposort.push_back(s);
        };
        
        
        
        for(int i =0 ; i < n ; i++) {
            if(source[i]) {
                dfs(i);
            }
        }
        
        if(toposort.size() != n) return false;

        vector<int> ntopo(n, 0);
        for(int i = 0; i< n; i++) {
            ntopo[toposort[i]] = i;
        }
        
        for(int i =0 ;i <n ;i++) {
            for(auto &j : adj[i]) {
                if(ntopo[i] < ntopo[j]) return false;
            }
        }
        return true;
        
    }
};
