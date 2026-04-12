class Solution {
public:
    void floodRemove(vector<vector<char>>& grid, int x, int y) {
        std::function<void(int,int)> recur = [&](int x, int y) {
            if(x < 0 || x > grid.size()-1) return;
            if(y < 0 || y > grid[x].size()-1) return;

            if(grid[x][y] == '1') {
                grid[x][y] = '0';
            } else {
                return;
            }

            recur(x-1,y);
            recur(x,y-1);
            recur(x,y+1);
            recur(x+1,y);
        };

        recur(x,y);
        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        int ct =  0;        
        for(int i = 0 ; i < grid.size();i++) {
            for(int j = 0; j < grid[i].size() ; j++) {
                if(grid[i][j] == '1') {
                    floodRemove(grid,i,j);
                    ct++;
                }
            }
        }
        return ct;
    }
};
