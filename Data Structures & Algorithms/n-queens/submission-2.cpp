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

    void backtrack(int queensLeft, int n , int idx , vector<string>&board, vector<vector<int>>&visited_board,  vector<vector<string>> &result){
        if(queensLeft == 0){
            result.push_back(board);
            return ;
        }

        // No more cells available
        if( idx >= (n*n)){
            return;
        }

        //current cell 
        int r = idx / n;
        int c = idx % n;
        
        if(visited_board[r][c] == 0){
            //place the queen and update the board and visited_board;
            board[r][c] = 'Q';
            makeMove(r, c, visited_board);
            backtrack(queensLeft-1, n, idx+1, board, visited_board, result);
            board[r][c] = '.';
            cancelMove(r, c, visited_board);
        }
        backtrack(queensLeft, n, idx+1, board, visited_board, result);
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
        backtrack(n,n, 0, board, visited_board, result);
        return result;
    }
};
