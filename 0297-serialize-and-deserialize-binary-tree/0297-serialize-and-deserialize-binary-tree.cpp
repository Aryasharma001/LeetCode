/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#,"; // Using '#' for null values.
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    int i=0;

    TreeNode* deserialize(string data) {
        if (i >= data.size()) return nullptr;

        // Get the current character
        char val = data[i++];

        // If it's a null marker ('#'), skip the comma and return nullptr
        if (val == '#') {
            i++;  // Skip the comma
            return nullptr;
        }

        // Parse the number (considering multi-digit numbers)
        string num;
        while (val != ',') {
            num += val;
            val = data[i++];
        }

        // Create a new TreeNode with the parsed integer value
        TreeNode* node = new TreeNode(stoi(num));

        // Recursively build the left and right subtrees
        node->left = deserialize(data);
        node->right = deserialize(data);

        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));