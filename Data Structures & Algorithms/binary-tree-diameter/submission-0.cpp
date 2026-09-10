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
    int maxDiameter = -1;
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int length = max(leftHeight, rightHeight) + 1;
        int diameter = leftHeight + rightHeight;
        maxDiameter = max(maxDiameter, diameter);
        return length;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return maxDiameter;
    }
};
