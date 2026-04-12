class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        auto flowCheck = [&](vector<vector<bool>>& flow, queue<pair<int,int>>& q) {
            list<pair<int,int>> cons = {
                {-1,0},
                {1,0},
                {0,1},
                {0,-1},
            };

            while(!q.empty()) {
                auto curr = q.front();
                q.pop();
                cout << curr.first<< " " << curr.second << endl;
                //verify while inserting if valid indices and not visited
                
                for(auto& [v,u] : cons) {
                    // index checks

                    int vx = curr.first + v;
                    int uy = curr.second + u;
                    if(vx < heights.size() && vx >= 0 && uy >= 0 && uy < heights[0].size()) {
                        if(heights[vx][uy] >= heights[curr.first][curr.second]) {
                            if(!flow[vx][uy]) {
                                flow[vx][uy] = true;
                                q.push({vx,uy});
                            }
                        }
                            
                    }
                }
            }
        };

        queue<pair<int,int>> qp;

        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        for(int i = 0; i < heights.size() ; i++) {
            qp.push({i,0});
            pacific[i][0] = true;
        }
        for(int i = 0; i < heights[0].size() ; i++) {
            qp.push({0,i});
            pacific[0][i] = true;
        }
        flowCheck(pacific, qp);

        queue<pair<int,int>> qa;

        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        for(int i = 0; i < heights.size() ; i++) {
            qa.push({i,heights[0].size()-1});
            atlantic[i][heights[0].size()-1] = true;
        }
        for(int i = 0; i < heights[0].size() ; i++) {
            qa.push({heights.size()-1,i});
            atlantic[heights.size()-1][i] = true;
        }
        flowCheck(atlantic, qa);

        vector<vector<int>> ans;
        for(int i = 0; i < heights.size() ; i++) {
            for(int j = 0; j < heights[0].size() ; j++) {
                if((pacific[i][j]) && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;


    }
};
