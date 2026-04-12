#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    const int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        struct bfsNode {
            int i;
            int j;
        };

        queue<bfsNode> q;
        for(int i =0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size() ;j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        while(!q.empty()) {
            bfsNode curr = q.front();
            q.pop();
            if(curr.i < 0 || curr.i > grid.size()-1 || curr.j < 0 || curr.j > grid[0].size()-1 ) continue;


            if(visited[curr.i][curr.j]) continue;
            visited[curr.i][curr.j] = true;
            // if(grid[curr.i][curr.j] > 0 && grid[curr.i][curr.j] != INF) continue;
            if(grid[curr.i][curr.j] == -1) continue;

            list<pair<int,int>> cons = {
                {curr.i+1,curr.j},
                {curr.i,curr.j+1},
                {curr.i-1,curr.j},
                {curr.i,curr.j-1},
            };

            for(auto &j : cons) {
                if(j.first < 0 || j.first > grid.size()-1 || j.second < 0 || j.second > grid[0].size()-1 ) continue;
                if(grid[j.first][j.second] == INF) {
                    grid[j.first][j.second] = grid[curr.i][curr.j] + 1;
                    q.push({j.first, j.second});
                } 
            }

        }
    }
};
