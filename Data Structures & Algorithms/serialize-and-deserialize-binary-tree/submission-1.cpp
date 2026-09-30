/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
    string preOrder(TreeNode* root, string& t){
        if(!root){
            t += "#,";
            return t;
        }
        t += to_string(root->val) + ",";
        preOrder(root->left, t);
        preOrder(root->right, t);
        return t;
    }

    TreeNode* buildTree(vector<string> preorder, int &i){
        if(preorder[i] == "#"){
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(preorder[i]));
        i++;
        root->left = buildTree(preorder, i);
        root->right = buildTree(preorder, i);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preOrder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>tree;
        string num ="";
        for(auto c : data){
            if(c == ','){
                tree.push_back(num);
                num = "";
            }else{
                num += c;
            }
        }
        int i = 0;
        return buildTree(tree, i);
    }
};
