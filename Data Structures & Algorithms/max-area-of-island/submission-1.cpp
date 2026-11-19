class Solution {
private: 
    int bfs(vector<vector<int>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row,col});
        grid[row][col]  = 0;
        int sum = 1;
        while(!q.empty()){
            pair<int, int> root = q.front();
            q.pop();
            int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
            for(auto& d : direction){
                int r = root.first + d[0];
                int c = root.second + d[1];
                if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1){
                    q.push({r,c});
                    grid[r][c] = 0; 
                    sum = sum + 1;
                }
            }
        }
        return sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0 ; 
        int row = grid.size() , col = grid[0].size();
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    ans = max(ans,  bfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
