class TreeNode{
    public :
        unordered_map<char, TreeNode*> children;
        bool endOfWord = false;
};

class PrefixTree {
    TreeNode* root;
public:
    PrefixTree() {  
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* cur =  root;
        for(auto c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TreeNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for(auto c : word){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(auto c : prefix){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
