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
public:
    string inorder(TreeNode* root, string &traversal){
        if(!root) return "";
        string leftRoot = inorder(root->left, traversal);
        traversal += to_string(root->val);
        string rightRoot = inorder(root->right, traversal);
        return traversal;
    }
    string preorder(TreeNode* root, string &traversal){
        if(!root) return "";
        traversal += to_string(root->val);
        string leftRoot = preorder(root->left, traversal);
        string rightRoot = preorder(root->right, traversal);
        return traversal;
    }
    TreeNode* buildTree(vector<int>inorder, vector<int>preorder){
        if(inorder.empty() && preorder.empty()) return nullptr;


        TreeNode* root = new TreeNode(preorder[0]);


        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> lfIn(inorder.begin(), inorder.begin()+mid);
        vector<int> rgIn(inorder.begin()+mid+1, inorder.end());
        vector<int> lfPre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> rgPre(preorder.begin()+mid+1, preorder.end());

        root->left = buildTree(lfIn, lfPre);
        root->right = buildTree(rgIn, rgPre);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        // inorder traversal 
        string inO = inorder(root, ans);
        ans += "#";
        // preorder traversal 
        string preO = preorder(root,ans );
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> inOrder ;
        vector<int> preOrder ;
        int i = 0;
        while( data[i] != '#'){
            int d = data[i] - '0';
            inOrder.push_back(d);
            i++;
        }
        i = i + 1;
        while(i != data.size()){
            int d = data[i] - '0';
            preOrder.push_back(d);
            i++;
        }
        TreeNode* root = buildTree(inOrder, preOrder);
        return root;
    }
};
