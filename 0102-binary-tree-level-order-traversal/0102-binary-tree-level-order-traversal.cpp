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
    void func(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return;
        if (level >= res.size()) {
            res.push_back(vector<int>()); // Add a new level if it doesn't exist
        }
        res[level].push_back(root->val);
        func(root->left, level + 1, res);
        func(root->right, level + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        func(root, 0, res);
        return res;
    }
};
