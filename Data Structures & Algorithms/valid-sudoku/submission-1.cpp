class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_map<int, unordered_set<char>> rows, cols, square;
       for(int r = 0; r < 9; r++){
        for(int c =0 ; c < 9 ; c++){
            char currentElement = board[r][c];

            if(currentElement == '.') continue;

            int squareKey = (r / 3) * 3 + (c / 3);

            if(rows[r].count(currentElement) || cols[c].count(currentElement) || 
                square[squareKey].count(currentElement))
            {
                return false;
            }
            rows[r].insert(currentElement);
            cols[c].insert(currentElement);
            square[squareKey].insert(currentElement);
        }
       }
       return true;
    }
};
