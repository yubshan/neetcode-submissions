class TreeNode{
    public:
        unordered_map<char, TreeNode*> children;
        bool final = false;
};
class WordDictionary {
    TreeNode* root;
public:
    WordDictionary() {
        root = new TreeNode;
    }
    
    void addWord(string word) {
        TreeNode* cur = root;
        for(auto c : word){
            if(!cur->children.count(c)){
                cur->children[c] = new TreeNode();
            }
            cur = cur->children[c];
        }
        cur->final = true;
    }
    
    bool search(string word) {
      return matchRest(root, 0, word);
    }
private:
    bool matchRest(TreeNode* root, int j, string word){
        TreeNode* cur = root;
        for(int i = j ; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto& [key, child] : cur->children){
                    if(child != nullptr && matchRest(child, i+1, word)){
                        return true;
                    }
                }
                return false;
            }else {
                if(!cur->children.count(c)){
                    return false;
                }
                cur = cur->children[c];
            }
        }
        return cur->final;
    }
};


