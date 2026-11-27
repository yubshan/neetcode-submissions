
class Solution {
private:
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    void dfs(vector<vector<char>>& board,
             int row, int col) {

        if (row < 0 || col < 0 ||
            row >= board.size() ||
            col >= board[0].size() ||
            board[row][col] != 'O') {
            return;
        }

        board[row][col] = 'F';


        for (auto d : directions) {
            int r = row + d[0];
            int c = col + d[1];

            dfs(board, r, c);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }

            if (board[n - 1][i] == 'O') {
                dfs(board, n - 1, i);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if(board[i][j] == 'O'){
                board[i][j] = 'X';
               }else if(board[i][j] == 'F'){
                board[i][j] = 'O';
               }
            }
        }
    }
};
