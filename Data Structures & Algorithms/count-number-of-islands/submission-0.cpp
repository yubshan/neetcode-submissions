class Solution {
private:
   void dfs(int row, int col, vector<vector<char>>&grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || 
            grid[row][col] == '0'){
                return;
        }
        grid[row][col] = '0';
        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);

   }
public:

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int row = grid.size() , col = grid[0].size();
        int island = 0;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    island++;
                }
            }
        }
       
       return island;
    }
};
