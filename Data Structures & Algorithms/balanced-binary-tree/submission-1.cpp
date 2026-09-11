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
    bool isBalanced(TreeNode* root) {
       if(root == nullptr){
         return true;
       }
       stack<pair<TreeNode*, bool>> st;
       unordered_map<TreeNode*, int> height;

       st.push({root, false});

       while(!st.empty()){
        auto[node, visited] = st.top();
        st.pop();

        if(node == nullptr) continue;

        if(!visited){
            st.push({node, true});
            st.push({node->right, false});
            st.push({node->left, false});
        }else{
            int lh = height[node->left];
            int rh = height[node->right];

            if(abs(lh-rh) > 1){
                return false;
            }
            height[node] = max(lh, rh) + 1;
        }
       }
       return true;
    }
};
