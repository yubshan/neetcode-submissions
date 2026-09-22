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
    int maxPathCost = INT_MIN;
    int treeCost(TreeNode* root){
        if(!root) return 0;
        int leftMaxCost = treeCost(root->left);
        int rightMaxCost = treeCost(root->right);
        leftMaxCost = leftMaxCost < 0 ? 0 : leftMaxCost;
        rightMaxCost = rightMaxCost < 0 ? 0 : rightMaxCost;
        maxPathCost = max(maxPathCost, (root->val+leftMaxCost+rightMaxCost));
        return (root->val + max(leftMaxCost,rightMaxCost));
    }
public:
    int maxPathSum(TreeNode* root) {
       treeCost(root);
       return maxPathCost;
    }
};
