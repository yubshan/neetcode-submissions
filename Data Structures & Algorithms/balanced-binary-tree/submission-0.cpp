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

class Solution {
    bool balanced= true;
    int height(TreeNode* root){
        if (root == nullptr) return 0;

        int lH = height(root->left);
        int rH = height(root->right);
        
        if(abs(lH - rH) > 1){
            balanced = false;
        }
        int length = max(lH, rH) + 1;

        return length;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
};
