#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    const int INF = 2147483647;

    int orangesRotting(vector<vector<int>>& grid) {
        struct bfsNode {
            int i;
            int j;
        };
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INF));

        queue<bfsNode> q;
        for(int i =0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size() ;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    distance[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            bfsNode curr = q.front();
            q.pop();

            if(grid[curr.i][curr.j] == 0) continue;

            list<pair<int,int>> cons = {
                {curr.i+1,curr.j},
                {curr.i,curr.j+1},
                {curr.i-1,curr.j},
                {curr.i,curr.j-1},
            };

            for(auto &j : cons) {
                if(j.first < 0 || j.first > grid.size()-1 || j.second < 0 || j.second > grid[0].size()-1 ) continue;
                cout << grid[j.first][j.second] << " " << distance[j.first][j.second] << endl;
                if(grid[j.first][j.second] == 1 && distance[j.first][j.second] == INF) {
                    distance[j.first][j.second] = distance[curr.i][curr.j] + 1;
                    q.push({j.first, j.second});
                } 
            }
        }


        int mx = 0;
        for (auto& row : distance) {
            for (int v : row) {
                if (v != INF)
                    mx = max(mx, v);
            }
        }

        for(int i =0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size() ;j++) {
                if(grid[i][j] == 1 && distance[i][j] == INF) {
                    return -1;
                }
            }
        }
        return mx;
    }
};
