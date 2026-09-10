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
    int diameterOfBinaryTree(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        stack<pair<TreeNode*, bool>> st;
        unordered_map<TreeNode*, int> height;

        int maxDiameter = 0;

        st.push({root, false});

        while (!st.empty()) {

            auto [node, visited] = st.top();
            st.pop();

            if (node == nullptr) {
                continue;
            }

            if (!visited) {
                st.push({node, true});
                st.push({node->right, false});
                st.push({node->left, false});
            }
            else {

                int leftHeight = height[node->left];
                int rightHeight = height[node->right];

                int currentDiameter = leftHeight + rightHeight;

                maxDiameter = max(maxDiameter, currentDiameter);

                height[node] =
                    max(leftHeight, rightHeight) + 1;
            }
        }

        return maxDiameter;
    }
};