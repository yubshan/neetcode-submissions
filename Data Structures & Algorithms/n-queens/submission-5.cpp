class Solution {
    void moveForRowAndCol(int cRow, int cCol, vector<vector<int>>& visited_board, bool undo){
        int n = visited_board.size();

        for (int i = 0; i < n; i++) {
            if (undo) visited_board[cRow][i]--;
            else visited_board[cRow][i]++;

            if (undo) visited_board[i][cCol]--;
            else visited_board[i][cCol]++;
        }
    }
    void moveForDiagonal(int cRow, int cCol, vector<vector<int>>& visited_board,  bool undo){
        int n = visited_board.size();

        int diff = cCol - cRow;
        int i = 0, j = 0;

        if (diff > 0) j = diff;
        else i = abs(diff);

        while (i < n && j < n) {
            if (undo) visited_board[i][j]--;
            else visited_board[i][j]++;

            i++;
            j++;
        }
    }
    void moveForAntiDiagonal(int cRow, int cCol, vector<vector<int>>& visited_board, bool undo){
         int n = visited_board.size();

        int sum = cCol + cRow;
        int i = 0, j = 0;

        if (sum >= n) {
            i = sum - (n - 1);
            j = n - 1;
        } else {
            j = sum;
        }

        while (i < n && j >= 0) {
            if (undo) visited_board[i][j]--;
            else visited_board[i][j]++;

            i++;
            j--;
        }
    }

    void makeMove(int cRow, int cCol, vector<vector<int>>& visited_board){
        moveForRowAndCol(cRow, cCol, visited_board, false);
        moveForDiagonal(cRow, cCol, visited_board, false);
        moveForAntiDiagonal(cRow, cCol, visited_board, false);
    }

    void cancelMove(int cRow, int cCol , vector<vector<int>>& visited_board){
        moveForRowAndCol(cRow, cCol, visited_board, true);
        moveForDiagonal(cRow, cCol, visited_board, true);
        moveForAntiDiagonal(cRow, cCol, visited_board, true);
    }

    void backtrack(int row, int n , vector<string>&board, vector<vector<int>>&visited_board,  vector<vector<string>> &result){
        if(row == n){
            result.push_back(board);
            return ;
        }
        for(int col = 0 ; col < n ; col++ ){
            bool isSafe = visited_board[row][col] == 0;
            if(isSafe){
                board[row][col] = 'Q';
                makeMove(row, col, visited_board);
                backtrack(row+1, n, board, visited_board, result);
                board[row][col] ='.';
                cancelMove(row, col, visited_board);
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> visited_board(n, vector<int>(n, 0));
        vector<string> board(n);
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                board[i].push_back('.');
            }
        }
        backtrack( 0,n, board, visited_board, result);
        return result;
    }
};
