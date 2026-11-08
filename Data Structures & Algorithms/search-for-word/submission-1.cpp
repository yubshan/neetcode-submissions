class Solution {
    bool backtrack(vector<vector<char>> & board, int& ans , string& target, int cIndex, int colsCount, int rowsCount){
        if(ans == target.size()){
            return true;
        }

        // check upper row
        if((cIndex/colsCount  > 0 )  && 
            (board[cIndex/colsCount - 1 ][cIndex % colsCount] == target[ans])){
             
            char temp = board[cIndex/colsCount - 1 ][cIndex % colsCount];
            board[cIndex/colsCount - 1 ][cIndex % colsCount] = '#';

            ans = ans+1;
            bool result =  backtrack(board, ans, target, (cIndex-colsCount), colsCount, rowsCount);
            if(result) return true;
            ans = ans-1;
            board[cIndex/colsCount - 1 ][cIndex % colsCount] = temp;
        }

        // check down row
        if((cIndex/colsCount + 1 < rowsCount) && 
            (board[cIndex/colsCount + 1 ][cIndex % colsCount] == target[ans])){
            
            char temp = board[cIndex/colsCount + 1 ][cIndex % colsCount];
            board[cIndex/colsCount + 1 ][cIndex % colsCount] = '#';

            ans = ans+1;
            bool result =  backtrack(board, ans, target, (cIndex + colsCount),colsCount, rowsCount);
            if(result) return true;
            ans = ans-1;
            board[cIndex/colsCount + 1 ][cIndex % colsCount] = temp;
        }

        // check right row
        if((cIndex % colsCount + 1 < colsCount)  && 
            (board[cIndex/colsCount][cIndex % colsCount + 1] == target[ans])){

            char temp = board[cIndex/colsCount][cIndex % colsCount + 1];
            board[cIndex/colsCount][cIndex % colsCount + 1] = '#';

            ans = ans+1;
            bool result =  backtrack(board, ans, target, (cIndex + 1), colsCount, rowsCount);
            if(result) return true;
            ans = ans-1;
            board[cIndex/colsCount][cIndex % colsCount + 1]=temp;
        }
        
        // check left row
        if((cIndex % colsCount > 0)  && 
            (board[cIndex/colsCount][cIndex % colsCount - 1] == target[ans])){

            char temp = board[cIndex/colsCount][cIndex % colsCount - 1];
            board[cIndex/colsCount][cIndex % colsCount - 1] = '#';
            ans = ans+1;
            bool result =  backtrack(board, ans, target, (cIndex - 1), colsCount, rowsCount);
            if(result) return true;
            ans = ans-1;
            board[cIndex/colsCount][cIndex % colsCount - 1] = temp;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowsCount = board.size();
        int colsCount = board[0].size();
        bool result;
        int ans = 0;
        if (board.empty() || board[0].empty() || word.empty()){
            return false;
        }
        for(int i = 0; i < (rowsCount * colsCount) ; i++){
            if(board[i/colsCount][i % colsCount] == word[0]){
                char temp = board[i/colsCount][i % colsCount];
                board[i/colsCount][i % colsCount] = '#';
                ans= ans+1;
                result = backtrack(board, ans, word, i,colsCount, rowsCount);
                if(result){
                    return true;
                }
                board[i/colsCount][i % colsCount] = temp;
                ans = ans-1;
            }else{
                continue;
            }
        }
        return false;
    }
};
