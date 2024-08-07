/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root == NULL)
            return false;
        path.push_back(root);
        if (root == p)
            return true;
        if (func(root->left, p, path) || func(root->right, p, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        vector<TreeNode*> p_path, q_path;
        func(root, p, p_path);
        func(root, q, q_path);

        TreeNode* ans = NULL;
        for (int i = 0; i < p_path.size() && i < q_path.size(); ++i) {
            if (p_path[i] == q_path[i]) {
                ans = p_path[i];
            } else {
                break;
            }
        }
        return ans;
    }
};