class Codec {
private:
    // Preorder: root -> left -> right
    void serializeTree(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(root->val) + ",";

        serializeTree(root->left, result);
        serializeTree(root->right, result);
    }

    // Reconstruct tree using preorder tokens
    TreeNode* deserializeTree(const vector<string>& nodes, int& index) {
        if (nodes[index] == "#") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = deserializeTree(nodes, index);
        root->right = deserializeTree(nodes, index);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeTree(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(token);
                token.clear();
            } else {
                token += c;
            }
        }

        int index = 0;
        return deserializeTree(nodes, index);
    }
};
