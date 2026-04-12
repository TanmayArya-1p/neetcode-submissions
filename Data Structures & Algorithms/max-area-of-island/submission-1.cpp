class Solution {
public:
    int floodRemove(vector<vector<int>>& grid, int x, int y) {


        int area = 0;
        std::function<void(int,int)> recur = [&](int x, int y) {
            if(x < 0 || x > grid.size()-1) return;
            if(y < 0 || y > grid[x].size()-1) return;

            if(grid[x][y] == 1) {
                area++;
                grid[x][y] = 0;
            } else {
                return;
            }

            recur(x-1,y);
            recur(x,y-1);
            recur(x,y+1);
            recur(x+1,y);
        };

        recur(x,y);
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mxarea = 0;        
        for(int i = 0 ; i < grid.size();i++) {
            for(int j = 0; j < grid[i].size() ; j++) {
                if(grid[i][j] == 1) {
                    mxarea = max(floodRemove(grid,i,j), mxarea);
                }
            }
        }
        return mxarea;
    }
};
