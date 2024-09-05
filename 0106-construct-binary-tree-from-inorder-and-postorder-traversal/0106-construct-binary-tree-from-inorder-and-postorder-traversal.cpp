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
    // Recursive function to build the tree
    TreeNode* buildSubtree(vector<int>& postorder, unordered_map<int, int>& inorder_map, int& postorderIndex, int inorderStart, int inorderEnd) {
        // Base case: if there are no elements to construct the tree
        if (inorderStart > inorderEnd || postorderIndex < 0) {
            return nullptr;
        }

        // The last element in postorder is the root of the current subtree
        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of this root in inorder traversal
        int inorderIndex = inorder_map[rootVal];

        // Build the right subtree first (because postorder is Left → Right → Root)
        root->right = buildSubtree(postorder, inorder_map, postorderIndex, inorderIndex + 1, inorderEnd);
        
        // Build the left subtree
        root->left = buildSubtree(postorder, inorder_map, postorderIndex, inorderStart, inorderIndex - 1);

        return root;
    }

    // Function to build the entire tree from postorder and inorder traversal
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map to store the index of each value in inorder traversal
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        // Initialize the postorder index to point to the last element
        int postorderIndex = postorder.size() - 1;

        // Call the recursive function to build the tree
        return buildSubtree(postorder, inorder_map, postorderIndex, 0, inorder.size() - 1);
    }
};
