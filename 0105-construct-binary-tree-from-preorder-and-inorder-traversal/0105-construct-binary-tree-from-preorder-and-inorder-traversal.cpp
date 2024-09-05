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
    // Function to recursively build the tree.
    TreeNode* func(vector<int>& preorder, unordered_map<int, int>& inorder_map, int& preorderIndex, int inorderStart, int inorderEnd) {
        // Base case: if there are no elements in the subtree
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

        // Get the current root value from the preorder traversal.
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root value in the inorder array.
        int inorderIndex = inorder_map[rootVal];

        // Recursively build the left and right subtrees.
        root->left = func(preorder, inorder_map, preorderIndex, inorderStart, inorderIndex - 1);
        root->right = func(preorder, inorder_map, preorderIndex, inorderIndex + 1, inorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in the inorder array.
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        // Initialize preorder index to 0 (start of preorder array).
        int preorderIndex = 0;

        // Call the recursive function to build the tree.
        return func(preorder, inorder_map, preorderIndex, 0, inorder.size() - 1);
    }
};
