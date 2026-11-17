class Solution {
    class TreeNode{
        public:
            unordered_map<char, TreeNode*> children;
            bool EOW = false;
    };

    class Tries{
        TreeNode* root;
        public:
            Tries(){
                root = new TreeNode();
            }   
            
            void addWord(string word){
                TreeNode* cur = root;
                for(auto c : word){
                    if(!cur->children.count(c)){
                        cur->children[c] = new TreeNode();
                    }
                    cur = cur->children[c];
                }
                cur->EOW = true;
            }

            void search(vector<string>& result, vector<vector<char>>& board){
               explore(root, result, board);
            }
        private:

            void backtrack(vector<vector<char>>&board, TreeNode* root ,vector<string>&result, string& word, int row, int col ){
                if(row < 0 || col < 0 || 
                    row >= board.size() || 
                    col >= board[0].size()|| 
                    board[row][col] == '#'){
                        return;
                    }
              
                char ch = board[row][col];
                if(!root->children.count(ch)){
                    return;
                }
                TreeNode* child = root->children[ch];

                word.push_back(ch);

                if(child->EOW){
                    result.push_back(word);
                    child->EOW = false;
                }

                board[row][col] = '#';
                backtrack(board, child, result, word, row-1, col);
                backtrack(board, child, result, word, row+1, col);
                backtrack(board, child, result, word, row, col-1);
                backtrack(board, child, result, word, row, col+1);
                board[row][col] = ch;
                word.pop_back();
            }
            void explore(TreeNode* root, vector<string>& result, vector<vector<char>>& board){
                string word;
                for(int j = 0 ; j <(board.size() * board[0].size()); j++){
                    backtrack(board, root, result, word , j / board[0].size(), j % board[0].size());
                }
            }
            
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        Tries* root = new Tries();
        for(auto w : words){
            root->addWord(w);
        }
        root->search(result, board);
        return result;
        
    }
};
