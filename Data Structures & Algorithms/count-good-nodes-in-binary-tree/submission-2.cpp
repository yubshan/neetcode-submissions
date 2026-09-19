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
    int goodNodeCount = 0;
    void dfs(TreeNode* root, int max){
        if(!root) return;
        int currentMax = max;
        if(root->val >= max){
            goodNodeCount++;
            currentMax = root->val;
        }
        dfs(root->left, currentMax);
        dfs(root->right, currentMax);
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return goodNodeCount;
    }
};
