class Solution {
private: 
    int dfs(vector<vector<int>>& grid, int & sum , int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || 
            col >= grid[0].size()   || grid[row][col] == 0) {
                return sum;
        }
        sum = sum+1;
        grid[row][col] = 0;
        dfs(grid, sum, row+1, col);
        dfs(grid, sum, row-1, col);
        dfs(grid, sum, row, col+1);
        dfs(grid, sum, row, col-1);
        return sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0 ; 
        int row = grid.size() , col = grid[0].size();
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    int sum = 0;
                    ans = max(ans,  dfs(grid, sum, i, j));
                }
            }
        }
        return ans;
    }
};
