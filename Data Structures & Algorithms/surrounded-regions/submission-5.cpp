class Solution {
public:

    void fillBFS(vector<vector<char>>& board, int x, int y) {
        queue<pair<int,int>> q;

        q.push({x,y});

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            board[curr.first][curr.second] = 'X';

            list<pair<int,int>> cons = {
                {1,0},
                {0,1},
                {0,-1},
                {-1,0},
            };

            for(auto& [u,v] : cons) {
                int nx = u+curr.first;
                int ny = v+curr.second;

                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[nx].size()) {
                    continue;
                } 
                
                if(board[nx][ny] == '-') {
                    q.push({nx,ny});
                }
            }
        }



    }

    bool checkBFS(vector<vector<char>>& board, int x, int y) {

        queue<pair<int,int>> q;

        q.push({x,y});
        board[x][y] = '-';
        
        vector<pair<int,int>> visited = {{x,y}};
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            cout << "CHECKING " << curr.first << " " << curr.second  << endl;



            list<pair<int,int>> cons = {
                {1,0},
                {0,1},
                {0,-1},
                {-1,0},
            };

            auto revert = [&]() {
                for(auto &[u,v] : visited) {
                    board[u][v] = 'O';
                }
            };

            for(auto& [u,v] : cons) {
                int nx = u+curr.first;
                int ny = v+curr.second;

                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[nx].size()) {
                    revert();
                    return false;
                } 
                
                if(board[nx][ny] == 'O') {
                    if(nx == 0 || nx == board.size()-1 || ny == 0 || ny == board[nx].size()-1) {
                        revert();
                        return false;
                    } 

                    board[nx][ny] = '-';
                    visited.push_back({nx,ny});
                    q.push({nx,ny});
                }
            }
        }

        return true;
    }

    void solve(vector<vector<char>>& board) {
        for(int i = 1; i < board.size()-1; i++) {
            for(int j = 1; j < board[i].size()-1; j++) {
                if(board[i][j] == 'O' ){
                    if (checkBFS(board, i, j)) {
                        cout << "NEED TO FILL" << endl;
                        fillBFS(board, i, j);
                    }
                } 
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'O';
                }
            }
        }

    }
};
