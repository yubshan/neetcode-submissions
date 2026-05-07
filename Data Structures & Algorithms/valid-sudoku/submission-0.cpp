class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>seen;
        //for row validation
        for(int row= 0 ; row< 9 ;row++){
            for(int col = 0 ; col < 9; col++ ){
                if(board[row][col] == '.') continue;
                if(seen.find(board[row][col]) != seen.end()) return false;
                seen.insert(board[row][col]);
            }
            seen.clear();
        }
        //for col validation
        for(int col = 0 ; col < 9; col++){
            for(int row = 0; row < 9 ; row++){
                if(board[row][col] == '.') continue;
                if(seen.find(board[row][col]) != seen.end()) return false;
                seen.insert(board[row][col]);
            }
            seen.clear();
        }
        //for square validation
        for(int square = 0; square < 9 ; square++){
            for(int i = 0 ; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.find(board[row][col]) != seen.end()) return false;
                    seen.insert(board[row][col]);
                }
            }
            seen.clear();
        }
        return true;
    }
};
