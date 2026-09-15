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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       vector<int>ls;
       queue<TreeNode*> q;
       if(!root){
            return ans;
       }
       q.push(root);
       TreeNode* last = q.back();

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            ls.push_back(node->val);
            if(last == node){
                ans.push_back(ls);
                ls.clear();
                if (!q.empty()) {
                    last = q.back();
                }
            }
        }
        return ans;
    }
};
