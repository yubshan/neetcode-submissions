class Solution {
private:
   void bfs(int row, int col, vector<vector<char>>&grid){
        queue<pair<int,int>> q;
        grid[row][col] = '0';
        q.push({row, col});

        while(!q.empty()){
            pair<int,int> root = q.front();
            q.pop();
            int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1} , {0,-1}};
            for(int i = 0 ; i < 4; i++){
                int r = root.first + direction[i][0] , c = root.second + direction[i][1];
                if(r >= 0  && c >= 0  && r < grid.size() &&
                    c < grid[0].size() && grid[r][c] == '1'){
                        q.push({r, c});
                        grid[r][c] = '0';
                    }
            }
        }
   }
public:

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int row = grid.size() , col = grid[0].size();
        int island = 0;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    island++;
                }
            }
        }
       
       return island;
    }
};
