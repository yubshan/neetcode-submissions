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
    bool isSame = true;
    void dfs(TreeNode* p, TreeNode* q){
        //base condition.
        if(q == nullptr && p== nullptr) return;

        // one is empty, other isn't.
        if(q== nullptr || p == nullptr) {
            isSame = false;
            return;
        }

        //different val.
        if(p->val != q->val){
            isSame = false;
            return;
        }

        //compare children.
        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return isSame;
    }
};
