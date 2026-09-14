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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode* > seen;
        TreeNode* ans = root;
        TreeNode* cur = root;
        // p ancestor saved 
        while(true){
            seen.insert(cur);
            if(p->val < cur->val){
                cur = cur->left;
            }else if(p->val > cur->val){
                cur = cur->right;
            }else{
                break;
            }
        }

        cur = root;
        // traverse q ancestor with cheking 
        while(true){
            if(seen.count(cur)){
                ans = cur;
            }
            if(q->val < cur->val){
                cur = cur->left;
            }else if(q->val > cur->val){
                cur = cur->right;
            }else{
                break;
            }
        }
        return ans; 
    }
};
