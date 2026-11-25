class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;


        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        // store position of the rotten fruit.
        for(int i =0 ; i<row; i++ ){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
        // pop and visit the neighbout cell
        while(!q.empty() && fresh > 0){
            int size = q.size();
    
            for(int i =0 ;i < size; i++){
                auto node = q.front();
                q.pop();
                for(auto d : directions){
                    int r = node.first + d[0];
                    int c = node.second + d[1];
                    if(r < 0 || c < 0 || r >=row || c >= col || grid[r][c] != 1 ){
                        continue;
                    }
                    grid[r][c] = 2;
                    fresh--;
                    q.push({r,c});
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
