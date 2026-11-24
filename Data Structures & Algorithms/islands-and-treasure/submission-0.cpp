
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Step 1: Add all treasures to the queue
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        int directions[4][2] = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        // Step 2: Multi-source BFS
        while(!q.empty()){

            auto [row, col] = q.front();
            q.pop();

            for(auto& d : directions){

                int r = row + d[0];
                int c = col + d[1];

                // Ignore invalid cells and already visited cells
                if(r < 0 || c < 0 ||
                   r >= m || c >= n ||
                   grid[r][c] != INT_MAX){
                    continue;
                }

                // Update distance
                grid[r][c] = grid[row][col] + 1;

                q.push({r,c});
            }
        }
    }
};
