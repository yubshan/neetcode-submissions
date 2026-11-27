class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        queue<pair<int, int>> q;


        for(int i = 0 ; i<n; i++ ){
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'A';
            }
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
                board[i][m-1] = 'A';

            } 
        }
        for(int j = 0 ; j < m; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = 'A';

            }
            if(board[n-1][j] == 'O') {
                q.push({n-1, j});
                board[n-1][j] = 'A';
            }
        }
        int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto d : directions){
                int r =  node.first + d[0];
                int c = node.second + d[1];
                if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O'){
                    continue;
                }
                board[r][c] = 'A';
                q.push({r, c});
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
               if(board[i][j] == 'A'){
                    board[i][j] = 'O';
               }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
               }else{
                    continue;
               }
            }
        }

        
    }
};
